#pragma once

#include "nlohmann/json.hpp"

enum class ShipCrewRotation {
  kStrict,
  kRelaxed,
};
NLOHMANN_JSON_SERIALIZE_ENUM(ShipCrewRotation,
                             {
                                 {ShipCrewRotation::kStrict, "STRICT"},
                                 {ShipCrewRotation::kRelaxed, "RELAXED"},
                             })

struct ShipCrew {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShipCrew, current, required, capacity,
                                 rotation, morale, wages)

 public:
  bool operator==(const ShipCrew&) const = default;

 public:
  int64_t current = 0;
  int64_t required = 0;
  int64_t capacity = 0;
  ShipCrewRotation rotation{};
  int64_t morale = 0;
  int64_t wages = 0;
};