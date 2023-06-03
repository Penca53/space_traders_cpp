#pragma once

#include <third_party/json.h>

struct SystemFaction {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(SystemFaction, symbol)

 public:
  std::string symbol;
};