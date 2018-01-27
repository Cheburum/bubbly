## Sinopsis
It is a simple 2d game demo with physics written in C++ using Unity3d-like gameobject/component system. I've tried to make it easy to extend and to upgrade
## Code example

1. Add new empty GameObject to game world.
```C++
  auto& newGameObject = scene.createGameObject();
```
2. Add Physics component to this object. All components require GameObject reference. And physComponent needs some physics info: mass, static or dynamic, is affected by gravity or not.
```C++
  newGameObject.addComponent("Physics", new PhysComponent(newGameObject, 0.0f, false, false));
```
3. We can get component from GO by name.
```C++
  const auto currentPhysComponent = newGameObject.getComponent<PhysComponent>("Physics")
```
4. Set the collider of physComponent.
```C++
  currentPhysComponent -> setCollider(Collider::rectangleCollider(glm::vec2(1.0f,3.0f));
```
5. Set GameObject's position.
```C++
  newGameObject.getTransform().position = glm::vec2(3.0f,4.0f);
```
## Installation
You will need GLFW3 and GLM  libraries to compile it.
### Debian/Ubuntu
```shell
sudo apt install libglfw3-dev libglm-dev
git clone https://github.com/Cheburum/bubbly.git
cd ./bubbly/src
cmake .
make
```
## License
GPLv3 (look LICENSE file in repository).

## Screenshot
![screenshot](./images/screenshot1.png)
