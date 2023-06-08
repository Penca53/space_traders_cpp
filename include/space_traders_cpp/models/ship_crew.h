#pragma once

#include "nlohmann/json.hpp"

enum class ShipCrewRotation {
  STRICT,
  RELAXED,
};
NLOHMANN_JSON_SERIALIZE_ENUM(ShipCrewRotation,
                             {
                                 {ShipCrewRotation::STRICT, "STRICT"},
                                 {ShipCrewRotation::RELAXED, "RELAXED"},
                             })

struct ShipCrew {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShipCrew, current, required, capacity,
                                 rotation, morale, wages)

 public:
  int64_t current = 0;
  int64_t required = 0;
  int64_t capacity = 0;
  ShipCrewRotation rotation{};
  int64_t morale = 0;
  int64_t wages = 0;
};