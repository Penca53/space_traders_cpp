#pragma once

#include "nlohmann/json.hpp"

struct WaypointOrbital {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(WaypointOrbital, symbol)

 public:
  std::string symbol;
};