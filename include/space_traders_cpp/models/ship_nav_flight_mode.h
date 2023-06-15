#pragma once

#include "nlohmann/json.hpp"

enum class ShipNavFlightMode {
  kCruise,
  kDrift,
  kStealth,
  kBurn,
};
NLOHMANN_JSON_SERIALIZE_ENUM(ShipNavFlightMode,
                             {
                                 {ShipNavFlightMode::kCruise, "CRUISE"},
                                 {ShipNavFlightMode::kDrift, "DRIFT"},
                                 {ShipNavFlightMode::kStealth, "STEALTH"},
                                 {ShipNavFlightMode::kBurn, "BURN"},
                             })