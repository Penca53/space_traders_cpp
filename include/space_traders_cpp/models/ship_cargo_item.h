#pragma once

#include "nlohmann/json.hpp"

struct ShipCargoItem {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShipCargoItem, symbol, name, description,
                                 units)

public:
  bool operator==(const ShipCargoItem&) const = default;

 public:
  std::string symbol;
  std::string name;
  std::string description;
  uint64_t units = 0;
};