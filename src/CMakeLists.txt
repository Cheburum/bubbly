cmake_minimum_required(VERSION 3.7)
project(bubbly)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES BubbleComponent.cpp BulletComponent.h CounterComponent.h BubbleComponent.h main.cpp
        BulletComponent.cpp CounterComponent.cpp GunComponent.cpp GunComponent.h TimerComponent.cpp TimerComponent.h)

add_executable(bubbly ${SOURCE_FILES})

add_subdirectory(engine)
target_link_libraries(bubbly BubblyEngine)