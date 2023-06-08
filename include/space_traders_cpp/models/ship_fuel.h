#pragma once

#include "nlohmann/json.hpp"
#include "space_traders_cpp/utility.h"

struct ShipFuelConsumed {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShipFuelConsumed, amount, timestamp)

 public:
  int64_t amount = 0;
  std::string timestamp;
};

struct ShipFuel {
 public:
  friend void to_json(nlohmann::json& j, const ShipFuel& sf) {
    j["current"] = sf.current;
    j["capacity"] = sf.capacity;
    j["consumed"] = sf.consumed;
  }
  friend void from_json(const nlohmann::json& j, ShipFuel& sf) {
    j.at("current").get_to(sf.current);
    j.at("capacity").get_to(sf.capacity);
    if (j.contains("consumed")) {
      j.at("consumed").get_to(sf.consumed);
    }
  }

 public:
  uint64_t current = 0;
  uint64_t capacity = 0;
  std::optional<ShipFuelConsumed> consumed;
};