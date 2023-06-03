#pragma once

#include "json.h"

struct WaypointOrbital {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(WaypointOrbital, symbol)

 public:
  std::string symbol;
};