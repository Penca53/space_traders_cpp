#pragma once

#include "nlohmann/json.hpp"

struct WaypointOrbital {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(WaypointOrbital, symbol)

 public:
  bool operator==(const WaypointOrbital&) const = default;

 public:
  std::string symbol;
};