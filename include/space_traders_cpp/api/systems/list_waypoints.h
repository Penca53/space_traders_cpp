#pragma once

#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/meta.h"
#include "space_traders_cpp/models/waypoint.h"

struct ListWaypointsRequest {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ListWaypointsRequest, systemSymbol)

 public:
  std::string systemSymbol;
  uint64_t limit = 10;
  uint64_t page = 1;
};
struct ListWaypointsResponse {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ListWaypointsResponse, data, meta)

 public:
  std::vector<Waypoint> data;
  Meta meta;
};