#pragma once

#include "nlohmann/json.hpp"
#include "space_traders_cpp/utility.h"

enum class MarketTransactionType {
  kPurchase,
  kSell,
};

NLOHMANN_JSON_SERIALIZE_ENUM(MarketTransactionType,
                             {
                                 {MarketTransactionType::kPurchase, "PURCHASE"},
                                 {MarketTransactionType::kSell, "SELL"},
                             })

struct MarketTransaction {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(MarketTransaction, waypointSymbol, shipSymbol,
                                 tradeSymbol, type, units, pricePerUnit,
                                 totalPrice, timestamp)

 public:
  bool operator==(const MarketTransaction&) const = default;

 public:
  std::string waypointSymbol;
  std::string shipSymbol;
  std::string tradeSymbol;
  MarketTransactionType type{};
  uint64_t units = 0;
  uint64_t pricePerUnit = 0;
  uint64_t totalPrice = 0;
  DateTime timestamp;
};