#pragma once

#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/trade_symbol.h"

struct TradeGood {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(TradeGood, symbol, name, description)

 public:
  bool operator==(const TradeGood&) const = default;

 public:
  TradeSymbol symbol{};
  std::string name;
  std::string description;
};