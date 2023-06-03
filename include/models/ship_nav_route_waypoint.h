#pragma once

#include "json.h"

#include "models/waypoint_type.h"

struct ShipNavRouteWaypoint {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShipNavRouteWaypoint, symbol, type,
                                 systemSymbol, x, y)

 public:
  std::string symbol;
  WaypointType type{};
  std::string systemSymbol;
  int64_t x = 0;
  int64_t y = 0;
};