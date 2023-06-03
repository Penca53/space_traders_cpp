#pragma once

#include <third_party/json.h>

#include "src/models/market_trade_good.h"
#include "src/models/market_transaction.h"
#include "src/models/trade_good.h"

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
  std::string symbol;
  std::vector<TradeGood> exports;
  std::vector<TradeGood> imports;
  std::vector<TradeGood> exchange;
  std::optional<std::vector<MarketTransaction>> transactions;
  std::optional<std::vector<MarketTradeGood>> tradeGoods;
};