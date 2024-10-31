cmake_minimum_required(VERSION 3.29)

project(Demo-3D-Engine
        LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(includes)
include_directories(includes/StellarForge)

link_directories(libs)

find_package(glm REQUIRED)
find_package(raylib REQUIRED)

add_executable(demo-3D-engine)

target_link_libraries(demo-3D-engine PUBLIC StellarForge3D StellarForgeGraphics3D StellarForgePhysics StellarForgeCommon glm::glm raylib)

target_sources(demo-3D-engine
        PUBLIC
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)
