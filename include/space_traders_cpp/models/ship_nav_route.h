#pragma once

#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/ship_nav_route_waypoint.h"
#include "space_traders_cpp/utility.h"

struct ShipNavRoute {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShipNavRoute, destination, departure,
                                 departureTime, arrival)

 public:
  bool operator==(const ShipNavRoute&) const = default;

 public:
  ShipNavRouteWaypoint destination{};
  ShipNavRouteWaypoint departure{};
  std::chrono::system_clock::time_point departureTime;
  std::chrono::system_clock::time_point arrival;
};