/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** RotatingCube.hpp
*/

#ifndef ROTATINGCUBE_HPP
#define ROTATINGCUBE_HPP

#include <chrono>
#include "StellarForge/Common/components/CPPMonoBehaviour.hpp"
#include "StellarForge/Common/components/Transform.hpp"
#include "StellarForge/Common/json/JsonObject.hpp"

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
    json::IJsonObject *serializeData() const override;
private:
    float speed = 1.00f;

#ifdef _WIN32
    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point actualTime;
#elif defined(__linux__)
    std::chrono::system_clock::time_point startTime;
    std::chrono::system_clock::time_point actualTime;
#else // macOS
    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point actualTime;
#endif
};

#endif //ROTATINGCUBE_HPP
