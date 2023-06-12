#pragma once

#include "nlohmann/json.hpp"

struct SystemFaction {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(SystemFaction, symbol)

public:
  bool operator==(const SystemFaction&) const = default;

 public:
  std::string symbol;
};