#pragma once

#include "json.h"

struct ShipCargoItem {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShipCargoItem, symbol, name, description,
                                 units)

 public:
  std::string symbol;
  std::string name;
  std::string description;
  uint64_t units = 0;
};