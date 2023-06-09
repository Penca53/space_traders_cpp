#pragma once

#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/shipyard_ship.h"
#include "space_traders_cpp/models/shipyard_transaction.h"

struct ShipyardShipType {
 public:
  friend void to_json(nlohmann::json& j, const ShipyardShipType& sst) {
    j["type"] = sst.type;
  }
  friend void from_json(const nlohmann::json& j, ShipyardShipType& sst) {
    if (j.contains("type")) {
      j.at("type").get_to(sst.type);
    }
  }

 public:
  bool operator==(const ShipyardShipType&) const = default;

 public:
  std::optional<ShipType> type;
};

struct Shipyard {
 public:
  friend void to_json(nlohmann::json& j, const Shipyard& s) {
    j["symbol"] = s.symbol;
    j["shipTypes"] = s.shipTypes;
    j["transactions"] = s.transactions;
    j["ships"] = s.ships;
  }
  friend void from_json(const nlohmann::json& j, Shipyard& s) {
    j.at("symbol").get_to(s.symbol);
    j.at("shipTypes").get_to(s.shipTypes);
    if (j.contains("transactions")) {
      j.at("transactions").get_to(s.transactions);
    }
    if (j.contains("ships")) {
      j.at("ships").get_to(s.ships);
    }
  }

 public:
  bool operator==(const Shipyard&) const = default;

 public:
  std::string symbol;
  std::vector<ShipyardShipType> shipTypes;
  std::optional<std::vector<ShipyardTransaction>> transactions;
  std::optional<std::vector<ShipyardShip>> ships;
};