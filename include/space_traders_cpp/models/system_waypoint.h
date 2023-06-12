#pragma once

#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/waypoint_type.h"

struct SystemWaypoint {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(SystemWaypoint, symbol, type, x, y)

 public:
  bool operator==(const SystemWaypoint&) const = default;

 public:
  std::string symbol;
  WaypointType type{};
  int64_t x = 0;
  int64_t y = 0;
};