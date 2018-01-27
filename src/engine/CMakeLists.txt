cmake_minimum_required(VERSION 3.7)
project(BubblyEngine)
set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES Scene.cpp Scene.h GameObject.cpp GameObject.h PhysComponent.cpp PhysComponent.h Transform.cpp Transform.h Component.cpp Component.h SpriteComponent.cpp SpriteComponent.h GlobalInfo.cpp GlobalInfo.h Collider.cpp Collider.h CollisionManager.cpp CollisionManager.h AbstractManager.cpp AbstractManager.h CleanManager.cpp CleanManager.h helpFunctions.h CameraComponent.cpp CameraComponent.h Texture.cpp Texture.h Clock.cpp Clock.h Mouse.cpp Mouse.h Keyboard.cpp Keyboard.h Window.cpp Window.h ShaderProgram.cpp ShaderProgram.h GLSLShader.cpp GLSLShader.h)

add_library(BubblyEngine ${SOURCE_FILES})
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/..")

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

if (NOT glfw3_FOUND)
    message(SEND_ERROR "SFML not found")
    return()
else ()
    target_link_libraries(BubblyEngine glfw ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})
endif ()