#pragma once

#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/ship_role.h"

struct ShipRegistration {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShipRegistration, name, factionSymbol, role)

 public:
  bool operator==(const ShipRegistration&) const = default;

 public:
  std::string name;
  std::string factionSymbol;
  ShipRole role{};
};