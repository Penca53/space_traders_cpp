#pragma once

#include "nlohmann/json.hpp"

struct WaypointFaction {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(WaypointFaction, symbol)

 public:
  bool operator==(const WaypointFaction&) const = default;

 public:
  std::string symbol;
};