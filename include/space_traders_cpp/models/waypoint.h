#pragma once

#include "nlohmann/json.hpp"

#include "space_traders_cpp/models/chart.h"
#include "space_traders_cpp/models/waypoint_faction.h"
#include "space_traders_cpp/models/waypoint_orbital.h"
#include "space_traders_cpp/models/waypoint_trait.h"
#include "space_traders_cpp/models/waypoint_type.h"

struct Waypoint {
 public:
  friend void to_json(nlohmann::json& j, const Waypoint& w) {
    j["symbol"] = w.symbol;
    j["type"] = w.type;
    j["systemSymbol"] = w.systemSymbol;
    j["x"] = w.x;
    j["y"] = w.y;
    j["orbitals"] = w.orbitals;
    j["faction"] = w.faction;
    j["traits"] = w.traits;
    j["chart"] = w.chart;
  }
  friend void from_json(const nlohmann::json& j, Waypoint& w) {
    j.at("symbol").get_to(w.symbol);
    j.at("type").get_to(w.type);
    j.at("systemSymbol").get_to(w.systemSymbol);
    j.at("x").get_to(w.x);
    j.at("y").get_to(w.y);
    j.at("orbitals").get_to(w.orbitals);
    if (j.contains("faction")) {
      j.at("faction").get_to(w.faction);
    }
    j.at("traits").get_to(w.traits);
    if (j.contains("chart")) {
      j.at("chart").get_to(w.chart);
    }
  }

 public:
  std::string symbol;
  WaypointType type{};
  std::string systemSymbol;
  int64_t x = 0;
  int64_t y = 0;
  std::vector<WaypointOrbital> orbitals;
  std::optional<WaypointFaction> faction;
  std::vector<WaypointTrait> traits;
  std::optional<Chart> chart;
};