#pragma once

#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/market_trade_good.h"
#include "space_traders_cpp/models/market_transaction.h"
#include "space_traders_cpp/models/trade_good.h"
#include "space_traders_cpp/utility.h"

struct Market {
 public:
  friend void to_json(nlohmann::json& j, const Market& m) {
    j["symbol"] = m.symbol;
    j["exports"] = m.exports;
    j["imports"] = m.imports;
    j["exchange"] = m.exchange;
    j["transactions"] = m.transactions;
    j["tradeGoods"] = m.tradeGoods;
  }
  friend void from_json(const nlohmann::json& j, Market& m) {
    j.at("symbol").get_to(m.symbol);
    j.at("exports").get_to(m.exports);
    j.at("imports").get_to(m.imports);
    j.at("exchange").get_to(m.exchange);
    if (j.contains("transactions")) {
      j.at("transactions").get_to(m.transactions);
    }
    if (j.contains("tradeGoods")) {
      j.at("tradeGoods").get_to(m.tradeGoods);
    }
  }

 public:
  bool operator==(const Market&) const = default;

 public:
  std::string symbol;
  std::vector<TradeGood> exports;
  std::vector<TradeGood> imports;
  std::vector<TradeGood> exchange;
  std::optional<std::vector<MarketTransaction>> transactions;
  std::optional<std::vector<MarketTradeGood>> tradeGoods;
};