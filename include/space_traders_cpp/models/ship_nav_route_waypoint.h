#pragma once

#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/waypoint_type.h"

struct ShipNavRouteWaypoint {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShipNavRouteWaypoint, symbol, type,
                                 systemSymbol, x, y)

 public:
  bool operator==(const ShipNavRouteWaypoint&) const = default;

 public:
  std::string symbol;
  WaypointType type{};
  std::string systemSymbol;
  int64_t x = 0;
  int64_t y = 0;
};