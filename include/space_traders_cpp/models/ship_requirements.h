#pragma once

#include "nlohmann/json.hpp"
#include "space_traders_cpp/utility.h"

struct ShipRequirements {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(ShipRequirements, power, crew,
                                              slots)

 public:
  std::optional<int64_t> power;
  std::optional<int64_t> crew;
  std::optional<int64_t> slots;
};