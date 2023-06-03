#pragma once

#include <third_party/json.h>

enum class MarketTradeGoodSupply {
  SCARCE,
  LIMITED,
  MODERATE,
  ABUNDANT,
};

NLOHMANN_JSON_SERIALIZE_ENUM(MarketTradeGoodSupply,
                             {
                                 {MarketTradeGoodSupply::SCARCE, "SCARCE"},
                                 {MarketTradeGoodSupply::LIMITED, "LIMITED"},
                                 {MarketTradeGoodSupply::MODERATE, "MODERATE"},
                                 {MarketTradeGoodSupply::ABUNDANT, "ABUNDANT"},
                             })

struct MarketTradeGood {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(MarketTradeGood, symbol, volume, supply,
                                 purchasePrice, sellPrice)

 public:
  std::string symbol;
  uint64_t volume = 0;
  MarketTradeGoodSupply supply{};
  uint64_t purchasePrice = 0;
  uint64_t sellPrice = 0;
};