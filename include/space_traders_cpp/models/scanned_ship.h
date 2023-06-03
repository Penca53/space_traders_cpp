#pragma once

#include "json.h"

#include "space_traders_cpp/models/ship_engine.h"
#include "space_traders_cpp/models/ship_frame.h"
#include "space_traders_cpp/models/ship_mount.h"
#include "space_traders_cpp/models/ship_nav.h"
#include "space_traders_cpp/models/ship_reactor.h"
#include "space_traders_cpp/models/ship_registration.h"

struct ScannedShip {
 public:
  friend void to_json(nlohmann::json& j, const ScannedShip& ss) {
    j["symbol"] = ss.symbol;
    j["registration"] = ss.registration;
    j["nav"] = ss.nav;
    j["frame"] = ss.frame;
    j["reactor"] = ss.reactor;
    j["engine"] = ss.engine;
    j["mounts"] = ss.mounts;
  }
  friend void from_json(const nlohmann::json& j, ScannedShip& ss) {
    j.at("symbol").get_to(ss.symbol);
    j.at("registration").get_to(ss.registration);
    j.at("nav").get_to(ss.nav);
    if (j.contains("frame")) {
      j.at("frame").get_to(ss.frame);
    }
    if (j.contains("reactor")) {
      j.at("reactor").get_to(ss.reactor);
    }
    j.at("engine").get_to(ss.engine);
    if (j.contains("mounts")) {
      j.at("mounts").get_to(ss.mounts);
    }
  }

 public:
  std::string symbol;
  ShipRegistration registration{};
  ShipNav nav{};
  std::optional<ShipFrame> frame;
  std::optional<ShipReactor> reactor;
  ShipEngine engine{};
  std::optional<std::vector<ShipMount>> mounts;
};