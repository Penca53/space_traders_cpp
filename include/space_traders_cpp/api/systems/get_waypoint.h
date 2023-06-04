#pragma once

#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/waypoint.h"

struct GetWaypointRequest {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(GetWaypointRequest, systemSymbol,
                                 waypointSymbol)

 public:
  std::string systemSymbol;
  std::string waypointSymbol;
};
struct GetWaypointResponse {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(GetWaypointResponse, data)

 public:
  Waypoint data;
};