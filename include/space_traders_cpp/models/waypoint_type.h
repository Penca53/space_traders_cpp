#pragma once

#include "json.h"

enum class WaypointType {
  PLANET,
  GAS_GIANT,
  MOON,
  ORBITAL_STATION,
  JUMP_GATE,
  ASTEROID_FIELD,
  NEBULA,
  DEBRIS_FIELD,
  GRAVITY_WELL,
};
NLOHMANN_JSON_SERIALIZE_ENUM(
    WaypointType, {
                      {WaypointType::PLANET, "PLANET"},
                      {WaypointType::GAS_GIANT, "GAS_GIANT"},
                      {WaypointType::MOON, "MOON"},
                      {WaypointType::ORBITAL_STATION, "ORBITAL_STATION"},
                      {WaypointType::JUMP_GATE, "JUMP_GATE"},
                      {WaypointType::ASTEROID_FIELD, "ASTEROID_FIELD"},
                      {WaypointType::NEBULA, "NEBULA"},
                      {WaypointType::DEBRIS_FIELD, "DEBRIS_FIELD"},
                      {WaypointType::GRAVITY_WELL, "GRAVITY_WELL"},
                  })