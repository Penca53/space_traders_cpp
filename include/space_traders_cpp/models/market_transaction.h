#pragma once

#include "nlohmann/json.hpp"

enum class MarketTransactionType {
  PURCHASE,
  SELL,
};

NLOHMANN_JSON_SERIALIZE_ENUM(MarketTransactionType,
                             {
                                 {MarketTransactionType::PURCHASE, "PURCHASE"},
                                 {MarketTransactionType::SELL, "SELL"},
                             })

struct MarketTransaction {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(MarketTransaction, waypointSymbol, shipSymbol,
                                 tradeSymbol, type, units, pricePerUnit,
                                 totalPrice, timestamp)

 public:
  std::string waypointSymbol;
  std::string shipSymbol;
  std::string tradeSymbol;
  MarketTransactionType type{};
  uint64_t units = 0;
  uint64_t pricePerUnit = 0;
  uint64_t totalPrice = 0;
  std::string timestamp;
};