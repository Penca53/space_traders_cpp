#pragma once

#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/ship_type.h"
#include "space_traders_cpp/models/system_type.h"
#include "space_traders_cpp/utility.h"

struct ConnectedSystem {
 public:
  friend void to_json(nlohmann::json& j, const ConnectedSystem& cs) {
    j["symbol"] = cs.symbol;
    j["sectorSymbol"] = cs.sectorSymbol;
    j["type"] = cs.type;
    j["factionSymbol"] = cs.factionSymbol;
    j["x"] = cs.x;
    j["y"] = cs.y;
    j["distance"] = cs.distance;
  }
  friend void from_json(const nlohmann::json& j, ConnectedSystem& cs) {
    j.at("symbol").get_to(cs.symbol);
    j.at("sectorSymbol").get_to(cs.sectorSymbol);
    j.at("type").get_to(cs.type);
    if (j.contains("factionSymbol")) {
      j.at("factionSymbol").get_to(cs.factionSymbol);
    }
    j.at("x").get_to(cs.x);
    j.at("y").get_to(cs.y);
    j.at("distance").get_to(cs.distance);
  }

 public:
  bool operator==(const ConnectedSystem&) const = default;

 public:
  std::string symbol;
  std::string sectorSymbol;
  SystemType type{};
  std::optional<std::string> factionSymbol;
  int64_t x = 0;
  int64_t y = 0;
  int64_t distance = 0;
};