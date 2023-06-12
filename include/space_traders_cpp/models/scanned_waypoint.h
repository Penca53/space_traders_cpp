#pragma once

#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/chart.h"
#include "space_traders_cpp/models/waypoint_faction.h"
#include "space_traders_cpp/models/waypoint_orbital.h"
#include "space_traders_cpp/models/waypoint_trait.h"
#include "space_traders_cpp/models/waypoint_type.h"

struct ScannedWaypoint {
 public:
  friend void to_json(nlohmann::json& j, const ScannedWaypoint& sw) {
    j["symbol"] = sw.symbol;
    j["type"] = sw.type;
    j["systemSymbol"] = sw.systemSymbol;
    j["x"] = sw.x;
    j["y"] = sw.y;
    j["orbitals"] = sw.orbitals;
    j["faction"] = sw.faction;
    j["traits"] = sw.traits;
    j["chart"] = sw.chart;
  }
  friend void from_json(const nlohmann::json& j, ScannedWaypoint& sw) {
    j.at("symbol").get_to(sw.symbol);
    j.at("type").get_to(sw.type);
    j.at("systemSymbol").get_to(sw.systemSymbol);
    j.at("x").get_to(sw.x);
    j.at("y").get_to(sw.y);
    j.at("orbitals").get_to(sw.orbitals);
    if (j.contains("faction")) {
      j.at("faction").get_to(sw.faction);
    }
    j.at("traits").get_to(sw.traits);
    if (j.contains("chart")) {
      j.at("chart").get_to(sw.chart);
    }
  }

 public:
  bool operator==(const ScannedWaypoint&) const = default;

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