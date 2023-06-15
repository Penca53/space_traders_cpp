#pragma once

#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/ship_requirements.h"
#include "space_traders_cpp/utility.h"

enum class ShipEngineSymbol {
  kEngineImpulseDriveI,
  kEngineIonDriveI,
  kEngineIonDriveII,
  kEngineHyperDriveI
};
NLOHMANN_JSON_SERIALIZE_ENUM(
    ShipEngineSymbol,
    {
        {ShipEngineSymbol::kEngineImpulseDriveI, "ENGINE_IMPULSE_DRIVE_I"},
        {ShipEngineSymbol::kEngineIonDriveI, "ENGINE_ION_DRIVE_I"},
        {ShipEngineSymbol::kEngineIonDriveII, "ENGINE_ION_DRIVE_II"},
        {ShipEngineSymbol::kEngineHyperDriveI, "ENGINE_HYPER_DRIVE_I"},
    })

struct ShipEngine {
 public:
  friend void to_json(nlohmann::json& j, const ShipEngine& se) {
    j["symbol"] = se.symbol;
    j["name"] = se.name;
    j["description"] = se.description;
    j["condition"] = se.condition;
    j["speed"] = se.speed;
    j["requirements"] = se.requirements;
  }
  friend void from_json(const nlohmann::json& j, ShipEngine& se) {
    j.at("symbol").get_to(se.symbol);
    j.at("name").get_to(se.name);
    j.at("description").get_to(se.description);
    if (j.contains("condition")) {
      j.at("condition").get_to(se.condition);
    }
    j.at("speed").get_to(se.speed);
    j.at("requirements").get_to(se.requirements);
  }

 public:
  bool operator==(const ShipEngine&) const = default;

 public:
  ShipEngineSymbol symbol{};
  std::string name;
  std::string description;
  std::optional<uint64_t> condition;
  int64_t speed = 0;
  ShipRequirements requirements{};
};