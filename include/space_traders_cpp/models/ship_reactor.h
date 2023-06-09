#pragma once

#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/ship_requirements.h"

enum class ShipReactorSymbol {
  kReactorSolarI,
  kReactorFusionI,
  kReactorFissionI,
  kReactorChemicalI,
  kReactorAntimatterI,
};
NLOHMANN_JSON_SERIALIZE_ENUM(
    ShipReactorSymbol,
    {
        {ShipReactorSymbol::kReactorSolarI, "REACTOR_SOLAR_I"},
        {ShipReactorSymbol::kReactorFusionI, "REACTOR_FUSION_I"},
        {ShipReactorSymbol::kReactorFissionI, "REACTOR_FISSION_I"},
        {ShipReactorSymbol::kReactorChemicalI, "REACTOR_CHEMICAL_I"},
        {ShipReactorSymbol::kReactorAntimatterI, "REACTOR_ANTIMATTER_I"},
    })

struct ShipReactor {
 public:
  friend void to_json(nlohmann::json& j, const ShipReactor& sr) {
    j["symbol"] = sr.symbol;
    j["name"] = sr.name;
    j["description"] = sr.description;
    j["condition"] = sr.condition;
    j["powerOutput"] = sr.powerOutput;
    j["requirements"] = sr.requirements;
  }
  friend void from_json(const nlohmann::json& j, ShipReactor& sr) {
    j.at("symbol").get_to(sr.symbol);
    j.at("name").get_to(sr.name);
    j.at("description").get_to(sr.description);
    if (j.contains("condition")) {
      j.at("condition").get_to(sr.condition);
    }
    j.at("powerOutput").get_to(sr.powerOutput);
    j.at("requirements").get_to(sr.requirements);
  }

 public:
  bool operator==(const ShipReactor&) const = default;

 public:
  ShipReactorSymbol symbol{};
  std::string name;
  std::string description;
  std::optional<uint64_t> condition;
  uint64_t powerOutput = 0;
  ShipRequirements requirements{};
};