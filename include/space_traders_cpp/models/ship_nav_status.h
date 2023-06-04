#pragma once

#include "nlohmann/json.hpp"

enum class ShipNavStatus {
  IN_TRANSIT,
  IN_ORBIT,
  DOCKED,
};
NLOHMANN_JSON_SERIALIZE_ENUM(ShipNavStatus,
                             {
                                 {ShipNavStatus::IN_TRANSIT, "IN_TRANSIT"},
                                 {ShipNavStatus::IN_ORBIT, "IN_ORBIT"},
                                 {ShipNavStatus::DOCKED, "DOCKED"},
                             })