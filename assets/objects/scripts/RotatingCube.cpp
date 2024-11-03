/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** RotatingCube.cpp
*/

#include "RotatingCube.hpp"

RotatingCube::RotatingCube(IObject *owner, const json::JsonObject *data) :
    CPPMonoBehaviour(owner, data) {}

void RotatingCube::start() {
    startTime = std::chrono::high_resolution_clock::now();
    actualTime = std::chrono::high_resolution_clock::now();
}

void RotatingCube::update() {
    actualTime = std::chrono::high_resolution_clock::now();
    if (std::chrono::duration<float, std::chrono::seconds::period>(actualTime - startTime).count() >= 0.01f) {
        auto *transform = getParentComponent<Transform>();
        transform->setRotation(glm::quat(transform->getRotation().w, transform->getRotation().x, transform->getRotation().y + 0.01f, transform->getRotation().z));
        startTime = actualTime;
    }
}

void RotatingCube::setSpeed(const float newSpeed) {
    speed = newSpeed;
}

float RotatingCube::getSpeed() const {
    return speed;
}

IComponent *RotatingCube::clone (IObject *owner) const {
    auto *comp = new RotatingCube(owner, nullptr);
    comp->speed = speed;
    return comp;
}

void RotatingCube::deserialize(const json::IJsonObject *data) {}

void RotatingCube::end() {}

json::IJsonObject *RotatingCube::serializeData() const {
    return nullptr;
}
