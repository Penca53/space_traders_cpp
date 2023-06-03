#pragma once

#include "json.h"

#include "space_traders_cpp/models/system_faction.h"
#include "space_traders_cpp/models/system_type.h"
#include "space_traders_cpp/models/system_waypoint.h"

struct ScannedSystem {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ScannedSystem, symbol, sectorSymbol, type, x,
                                 y, distance)

 public:
  std::string symbol;
  std::string sectorSymbol;
  SystemType type{};
  int64_t x = 0;
  int64_t y = 0;
  int64_t distance = 0;
};