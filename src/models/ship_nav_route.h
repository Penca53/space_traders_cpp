#pragma once

#include <third_party/json.h>

#include "src/models/ship_nav_route_waypoint.h"

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