#pragma once

#include "json.h"

struct ShipRequirements {
 public:
  friend void to_json(nlohmann::json& j, const ShipRequirements& sr) {
    j["power"] = sr.power;
    j["crew"] = sr.crew;
    j["slots"] = sr.slots;
  }
  friend void from_json(const nlohmann::json& j, ShipRequirements& sr) {
    if (j.contains("power")) {
      j.at("power").get_to(sr.power);
    }
    if (j.contains("crew")) {
      j.at("crew").get_to(sr.crew);
    }
    if (j.contains("slots")) {
      j.at("slots").get_to(sr.slots);
    }
  }

 public:
  std::optional<int64_t> power;
  std::optional<int64_t> crew;
  std::optional<int64_t> slots;
};