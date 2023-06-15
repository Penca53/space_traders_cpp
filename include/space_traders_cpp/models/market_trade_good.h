#pragma once

#include "nlohmann/json.hpp"

enum class MarketTradeGoodSupply {
  kScarce,
  kLimited,
  kModerate,
  kAbundant,
};

NLOHMANN_JSON_SERIALIZE_ENUM(MarketTradeGoodSupply,
                             {
                                 {MarketTradeGoodSupply::kScarce, "SCARCE"},
                                 {MarketTradeGoodSupply::kLimited, "LIMITED"},
                                 {MarketTradeGoodSupply::kModerate, "MODERATE"},
                                 {MarketTradeGoodSupply::kAbundant, "ABUNDANT"},
                             })

struct MarketTradeGood {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(MarketTradeGood, symbol, volume, supply,
                                 purchasePrice, sellPrice)

 public:
  bool operator==(const MarketTradeGood&) const = default;

 public:
  std::string symbol;
  uint64_t volume = 0;
  MarketTradeGoodSupply supply{};
  uint64_t purchasePrice = 0;
  uint64_t sellPrice = 0;
};