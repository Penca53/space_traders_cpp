#pragma once

#include "nlohmann/json.hpp"

#include "space_traders_cpp/models/ship_engine.h"
#include "space_traders_cpp/models/ship_frame.h"
#include "space_traders_cpp/models/ship_module.h"
#include "space_traders_cpp/models/ship_mount.h"
#include "space_traders_cpp/models/ship_reactor.h"
#include "space_traders_cpp/models/ship_type.h"

struct ShipyardShip {
 public:
  friend void to_json(nlohmann::json& j, const ShipyardShip& ss) {
    j["type"] = ss.type;
    j["name"] = ss.name;
    j["description"] = ss.description;
    j["purchasePrice"] = ss.purchasePrice;
    j["frame"] = ss.frame;
    j["reactor"] = ss.reactor;
    j["engine"] = ss.engine;
    j["modules"] = ss.modules;
    j["mounts"] = ss.mounts;
  }
  friend void from_json(const nlohmann::json& j, ShipyardShip& ss) {
    if (j.contains("type")) {
      j.at("type").get_to(ss.type);
    }
    j.at("name").get_to(ss.name);
    j.at("description").get_to(ss.description);
    j.at("purchasePrice").get_to(ss.purchasePrice);
    j.at("frame").get_to(ss.frame);
    j.at("reactor").get_to(ss.reactor);
    j.at("engine").get_to(ss.engine);
    j.at("modules").get_to(ss.modules);
    j.at("mounts").get_to(ss.mounts);
  }

 public:
  std::optional<ShipType> type{};
  std::string name;
  std::string description;
  int64_t purchasePrice = 0;
  ShipFrame frame{};
  ShipReactor reactor{};
  ShipEngine engine{};
  std::vector<ShipModule> modules;
  std::vector<ShipMount> mounts;
};