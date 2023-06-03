#pragma once

#include "json.h"

#include "models/ship_requirements.h"

struct ShipFrame {
 public:
  friend void to_json(nlohmann::json& j, const ShipFrame& sf) {
    j["symbol"] = sf.symbol;
    j["name"] = sf.name;
    j["description"] = sf.description;
    j["condition"] = sf.condition;
    j["moduleSlots"] = sf.moduleSlots;
    j["mountingPoints"] = sf.mountingPoints;
    j["fuelCapacity"] = sf.fuelCapacity;
    j["requirements"] = sf.requirements;
  }
  friend void from_json(const nlohmann::json& j, ShipFrame& sf) {
    j.at("symbol").get_to(sf.symbol);
    j.at("name").get_to(sf.name);
    j.at("description").get_to(sf.description);
    if (j.contains("condition")) {
      j.at("condition").get_to(sf.condition);
    }
    j.at("moduleSlots").get_to(sf.moduleSlots);
    j.at("mountingPoints").get_to(sf.mountingPoints);
    j.at("fuelCapacity").get_to(sf.fuelCapacity);
    j.at("requirements").get_to(sf.requirements);
  }

 public:
  std::string symbol;
  std::string name;
  std::string description;
  std::optional<uint64_t> condition;
  int64_t moduleSlots = 0;
  int64_t mountingPoints = 0;
  int64_t fuelCapacity = 0;
  ShipRequirements requirements{};
};