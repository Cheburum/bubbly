cmake_minimum_required(VERSION 3.7)
project(BubblyEngine)
set(SOURCE_FILES Scene.cpp Scene.h GameObject.cpp GameObject.h PhysComponent.cpp PhysComponent.h Transform.cpp Transform.h Component.cpp Component.h SpriteComponent.cpp SpriteComponent.h GlobalInfo.cpp GlobalInfo.h Collider.cpp Collider.h CollisionManager.cpp CollisionManager.h AbstractManager.cpp AbstractManager.h CleanManager.cpp CleanManager.h helpFunctions.h CameraComponent.cpp CameraComponent.h helpFunctions.cpp)

add_library(BubblyEngine ${SOURCE_FILES})
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/..")

find_package(SFML COMPONENTS system window graphics REQUIRED)
if (NOT SFML_FOUND)
    message(SEND_ERROR "SFML not found")
    return()
else ()
    target_link_libraries(BubblyEngine ${SFML_LIBRARIES})
endif ()
