## Sinopsis
It is a simple 2d game demo with physics written in C++ using Unity3d-like gameobject/component system. I've tryed to make it easy to extend and to upgrade.
## Code example
```C++
  gameObjects.push_front(GameObject(info)); //Add new empty GameObject(GO) to game world
  gameObjects.front().addComponent("Physics", //add Physics component to this object
                                       new PhysComponent(gameObjects.front(), 0.0f, false, false));
                                       //Component requires GO reference and some physics info like "is it static or dynamic"
  const auto currentPhysComponent = (PhysComponent *) gameObjects.front().getComponent("Physics");
  //We can get component from GO by name
  currentPhysComponent->setCollider(Collider::rectangleCollider(size)); //Setting collider of physComponent
  gameObjects.front().getTransform().position = position; //setting GO position
```
## Installation
You will need SFML library to compile it.
### Ubuntu
```shell
sudo apt install libsfml-dev
git clone https://github.com/Cheburum/bubbly.git
cd ./bubbly
cmake .
make
```
## License
GPLv3 (look LICENSE file in repository).

## Screenshot
![screenshot](./images/screenshot1.png)
