#pragma once

#include "nlohmann/json.hpp"

enum class ShipNavStatus {
  kInTransit,
  kInOrbit,
  kDocked,
};
NLOHMANN_JSON_SERIALIZE_ENUM(ShipNavStatus,
                             {
                                 {ShipNavStatus::kInTransit, "IN_TRANSIT"},
                                 {ShipNavStatus::kInOrbit, "IN_ORBIT"},
                                 {ShipNavStatus::kDocked, "DOCKED"},
                             })