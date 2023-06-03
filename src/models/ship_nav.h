#pragma once

#include <third_party/json.h>

#include "src/models/ship_nav_flight_mode.h"
#include "src/models/ship_nav_route.h"
#include "src/models/ship_nav_status.h"

struct ShipNav {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShipNav, systemSymbol, waypointSymbol, route,
                                 status, flightMode)

 public:
  std::string systemSymbol;
  std::string waypointSymbol;
  ShipNavRoute route{};
  ShipNavStatus status{};
  ShipNavFlightMode flightMode{};
};