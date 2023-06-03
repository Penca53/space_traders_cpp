#pragma once

#include "json.h"

#include "models/ship_nav_flight_mode.h"
#include "models/ship_nav_route.h"
#include "models/ship_nav_status.h"

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