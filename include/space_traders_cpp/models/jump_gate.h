#pragma once

#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/connected_system.h"
#include "space_traders_cpp/utility.h"

struct JumpGate {
 public:
  friend void to_json(nlohmann::json& j, const JumpGate& jg) {
    j["jumpRange"] = jg.jumpRange;
    j["factionSymbol"] = jg.factionSymbol;
    j["connectedSystems"] = jg.connectedSystems;
  }
  friend void from_json(const nlohmann::json& j, JumpGate& jg) {
    j.at("jumpRange").get_to(jg.jumpRange);
    if (j.contains("factionSymbol")) {
      j.at("factionSymbol").get_to(jg.factionSymbol);
    }
    j.at("connectedSystems").get_to(jg.connectedSystems);
  }

 public:
  int64_t jumpRange = 0;
  std::optional<std::string> factionSymbol;
  std::vector<ConnectedSystem> connectedSystems;
};