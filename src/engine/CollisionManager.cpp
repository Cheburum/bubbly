//
// Created by cheburum on 15.07.17.
//

#include <cmath>
#include "CollisionManager.h"
#include "PhysComponent.h"

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

void CollisionManager::add(Component *const x) {
    objects.push_back((PhysComponent*)x);
}

sf::Vector2f abs(sf::Vector2f arg){
    return sf::Vector2f(std::abs(arg.x),std::abs(arg.y));
}

bool CollisionManager::checkCollisions(PhysComponent* a, PhysComponent* b){ //returns true if collision detected
    //and moves one of the object to correct position without overlapping
    if(a->collider.getType()==CIRCLE&&b->collider.getType()==CIRCLE){
        const auto disVec = a->gameObject.getTransform().position-b->gameObject.getTransform().position;
        const auto radSum = a->collider.getRadius()+b->collider.getRadius();
        const auto centerDistance = (float)sqrt(disVec.x*disVec.x+disVec.y*disVec.y);
        const auto result = radSum>=centerDistance;
        if(result) {
            const auto depthVec = disVec/centerDistance*(radSum-centerDistance);
            a->gameObject.getTransform().position += depthVec;
        }
        return result;
    }
    else if(a->collider.getType()==RECTANGLE&&b->collider.getType()==RECTANGLE){
        const auto disVec = abs(a->gameObject.getTransform().position-b->gameObject.getTransform().position);
        const auto acolSize=a->collider.getSize();
        const auto bcolSize=b->collider.getSize();
        return disVec.x<=acolSize.x/2+bcolSize.x/2&&disVec.y<=acolSize.y/2+bcolSize.y/2;
    }else{
        //Next if is to make a=CIRCLE,b=RECTANGLE (sorted)
        if(a->collider.getType()>b->collider.getType())
            std::swap(a,b);
        if(a->collider.getType()==CIRCLE&&b->collider.getType()==RECTANGLE){
            const auto dvec = a->gameObject.getTransform().position-b->gameObject.getTransform().position;
            const auto absVec=abs(dvec);
            const auto rectSize=b->collider.getSize();
            const auto radius = a->collider.getRadius();
            const auto pvec = rectSize/2.0f+sf::Vector2f(radius,radius)-absVec;
            const bool result = pvec.x>0&&pvec.y>0;
            if(result){
                if(pvec.x<pvec.y){
                    a->gameObject.getTransform().position.x+=pvec.x*sgn(dvec.x);
                }else{
                    a->gameObject.getTransform().position.y+=pvec.y*sgn(dvec.y);
                }
            }
            return result;
        }
    }
    //TODO COLLISION CHECK FOR OTHER TYPES
    return false;
}

void CollisionManager::update(){
    for(auto& el: objects)
        el->collisions.clear();
    for(auto i=0;i<objects.size();++i)
        for(auto j=i+1;j<objects.size();++j){
            if(checkCollisions(objects[i],objects[j])) {
                objects[i]->collisions.push_back(objects[j]); //now PhysComponent knows about detected collisions
                objects[j]->collisions.push_back(objects[i]);
            }
        }
}

void CollisionManager::remove(Component *x) {
    objects.erase(std::find(objects.begin(), objects.end(), (PhysComponent*)x));
}