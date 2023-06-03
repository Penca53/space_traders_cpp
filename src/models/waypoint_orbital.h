#pragma once

#include <third_party/json.h>

struct WaypointOrbital {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(WaypointOrbital, symbol)

 public:
  std::string symbol;
};