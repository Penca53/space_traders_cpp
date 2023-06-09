#pragma once

#include "nlohmann/json.hpp"

#include "space_traders_cpp/models/ship_cargo_item.h"

struct ShipCargo {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShipCargo, capacity, units, inventory)

public:
  bool operator==(const ShipCargo&) const = default;

 public:
  uint64_t capacity = 0;
  uint64_t units = 0;
  std::vector<ShipCargoItem> inventory;
};