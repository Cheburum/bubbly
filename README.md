## Sinopsis
It is a simple 2d game demo with physics written in C++ using Unity3d-like gameobject/component system. I've tryed to make it easy to extend and to upgrade.
## Code example
```C++
  auto& newGameObject = gameObject.getWorldInfo().getScene().createGameObject();; //Add new empty GameObject(GO) to game world
  newGameObject.addComponent("Physics", //add Physics component to this object
                                       new PhysComponent(newGameObject, 0.0f, false, false));
                                       //Component requires GO reference and some physics info like "is it static or dynamic"
  const auto currentPhysComponent = (PhysComponent *) newGameObject.getComponent("Physics");
  //We can get component from GO by name
  currentPhysComponent->setCollider(Collider::rectangleCollider(sf::Vector2f(10.0f,30.0f)); //Setting collider of physComponent
  newGameObject.getTransform().position = sf::Vector2f(423.0f,44.0f); //setting GO position
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
