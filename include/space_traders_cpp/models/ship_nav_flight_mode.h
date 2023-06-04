#pragma once

#include "nlohmann/json.hpp"

enum class ShipNavFlightMode {
  CRUISE,
  DRIFT,
  STEALTH,
  BURN,
};
NLOHMANN_JSON_SERIALIZE_ENUM(ShipNavFlightMode,
                             {
                                 {ShipNavFlightMode::CRUISE, "CRUISE"},
                                 {ShipNavFlightMode::DRIFT, "DRIFT"},
                                 {ShipNavFlightMode::STEALTH, "STEALTH"},
                                 {ShipNavFlightMode::BURN, "BURN"},
                             })