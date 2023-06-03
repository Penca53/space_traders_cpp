#pragma once

#include "json.h"

#include "models/meta.h"
#include "models/waypoint.h"

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