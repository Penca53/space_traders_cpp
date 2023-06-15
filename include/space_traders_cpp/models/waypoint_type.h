#pragma once

#include "nlohmann/json.hpp"

enum class WaypointType {
  kPlanet,
  kGasGiant,
  kMoon,
  kOrbitalStation,
  kJumpGate,
  kAsteroidField,
  kNebula,
  kDebrisField,
  kGravityWell,
};
NLOHMANN_JSON_SERIALIZE_ENUM(
    WaypointType, {
                      {WaypointType::kPlanet, "PLANET"},
                      {WaypointType::kGasGiant, "GAS_GIANT"},
                      {WaypointType::kMoon, "MOON"},
                      {WaypointType::kOrbitalStation, "ORBITAL_STATION"},
                      {WaypointType::kJumpGate, "JUMP_GATE"},
                      {WaypointType::kAsteroidField, "ASTEROID_FIELD"},
                      {WaypointType::kNebula, "NEBULA"},
                      {WaypointType::kDebrisField, "DEBRIS_FIELD"},
                      {WaypointType::kGravityWell, "GRAVITY_WELL"},
                  })