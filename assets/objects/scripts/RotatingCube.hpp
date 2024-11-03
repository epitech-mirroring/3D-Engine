/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** RotatingCube.hpp
*/

#ifndef ROTATINGCUBE_HPP
#define ROTATINGCUBE_HPP

#include <chrono>
#include "common/components/CPPMonoBehaviour.hpp"
#include "common/components/Transform.hpp"
#include "common/json/JsonObject.hpp"

class RotatingCube final : public CPPMonoBehaviour {
public:
    RotatingCube(IObject *owner, const json::JsonObject *data);
    ~RotatingCube() override = default;

    void start() override;
    void update() override;

    void setSpeed(float newSpeed);
    [[nodiscard]] float getSpeed() const;

    IComponent *clone (IObject *owner) const override;
    void deserialize(const json::IJsonObject *data) override;
    void end() override;
    json::IJsonObject *serializeData() override;
private:
    float speed = 1.00f;

#ifdef _WIN32
    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point actualTime;
#else
    std::chrono::system_clock::time_point startTime;
    std::chrono::system_clock::time_point actualTime;
#endif // _WIN32
};

#endif //ROTATINGCUBE_HPP
