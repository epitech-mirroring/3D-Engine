cmake_minimum_required(VERSION 3.29)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Demo-3D-Engine
        LANGUAGES CXX)

add_executable(demo-3D-engine)

find_package(stellar-forge-3d REQUIRED)
find_package(glm REQUIRED)
target_link_libraries(demo-3D-engine PUBLIC stellar-forge-3d::stellar-forge-3d glm::glm)

target_sources(demo-3D-engine
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/assets/objects/scripts/RotatingCube.hpp
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/assets/objects/scripts/RotatingCube.cpp
)

install(TARGETS demo-3D-engine
        RUNTIME DESTINATION bin
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/assets
        DESTINATION bin
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)
