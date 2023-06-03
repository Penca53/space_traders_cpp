#pragma once

#include <third_party/json.h>

#include "src/models/ship_role.h"

struct ShipRegistration {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShipRegistration, name, factionSymbol, role)

 public:
  std::string name;
  std::string factionSymbol;
  ShipRole role{};
};