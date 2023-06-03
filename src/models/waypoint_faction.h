#pragma once

#include <third_party/json.h>

struct WaypointFaction {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(WaypointFaction, symbol)

 public:
  std::string symbol;
};