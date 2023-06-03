#pragma once

#include "json.h"

struct SystemFaction {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(SystemFaction, symbol)

 public:
  std::string symbol;
};