#pragma once

#include <third_party/json.h>

#include "src/models/system.h"

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
  std::vector<System> connectedSystems;
};