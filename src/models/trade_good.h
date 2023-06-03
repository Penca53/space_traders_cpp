#pragma once

#include <third_party/json.h>

#include "src/models/trade_symbol.h"

struct TradeGood {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(TradeGood, symbol, name, description)

 public:
  TradeSymbol symbol{};
  std::string name;
  std::string description;
};