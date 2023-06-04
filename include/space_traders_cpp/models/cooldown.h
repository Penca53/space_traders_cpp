#pragma once

#include "json.h"

struct Cooldown {
 public:
  friend void to_json(nlohmann::json& j, const Cooldown& c) {
    j["shipSymbol"] = c.shipSymbol;
    j["totalSeconds"] = c.totalSeconds;
    j["remainingSeconds"] = c.remainingSeconds;
    j["expiration"] = c.expiration;
  }
  friend void from_json(const nlohmann::json& j, Cooldown& c) {
    j.at("shipSymbol").get_to(c.shipSymbol);
    j.at("totalSeconds").get_to(c.totalSeconds);
    j.at("remainingSeconds").get_to(c.remainingSeconds);
    if (j.contains("expiration")) {
      j.at("expiration").get_to(c.expiration);
    }
  }

 public:
  std::string shipSymbol;
  uint64_t totalSeconds = 0;
  uint64_t remainingSeconds = 0;
  std::optional<std::string> expiration;
};