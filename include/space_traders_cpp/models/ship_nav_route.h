#pragma once

#include "json.h"

#include "space_traders_cpp/models/ship_nav_route_waypoint.h"

struct ShipNavRoute {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShipNavRoute, destination, departure,
                                 departureTime, arrival)

 public:
  ShipNavRouteWaypoint destination{};
  ShipNavRouteWaypoint departure{};
  std::string departureTime;
  std::string arrival;
};