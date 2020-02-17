cmake_minimum_required(VERSION 3.6) # Проверка версии CMake.

add_definitions(-Wextra -Wno-unused-parameter)

set(Core_SOURCES
    Core.h
    Core.cpp
    ICoreAppDelegate.h
    IScene.h
    IRender.h
    IFactoryScene.h
    IManagerScene.h
    IDescriptionScene.h
    IManagerDescriptionScene.h
    SessionApp.h
    SessionApp.cpp
    ManagerDescriptionScene.h
    ManagerDescriptionScene.cpp
    Render.h
    Render.cpp
    ManagerScene.h
    ManagerScene.cpp
    CoreAppDelegate.h
    CoreAppDelegate.cpp
)

add_library(Core_LIB STATIC ${Core_SOURCES})

find_package(StateMachine_LIB)
target_link_libraries(Core_LIB StateMachine_LIB)
