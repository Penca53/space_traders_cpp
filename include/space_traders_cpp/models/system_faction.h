#pragma once

#include "nlohmann/json.hpp"

struct SystemFaction {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(SystemFaction, symbol)

 public:
  std::string symbol;
};