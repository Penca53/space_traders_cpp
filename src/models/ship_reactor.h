#pragma once

#include <third_party/json.h>

#include "src/models/ship_requirements.h"

enum class ShipReactorSymbol {
  REACTOR_SOLAR_I,
  REACTOR_FUSION_I,
  REACTOR_FISSION_I,
  REACTOR_CHEMICAL_I,
  REACTOR_ANTIMATTER_I,
};
NLOHMANN_JSON_SERIALIZE_ENUM(
    ShipReactorSymbol,
    {
        {ShipReactorSymbol::REACTOR_SOLAR_I, "REACTOR_SOLAR_I"},
        {ShipReactorSymbol::REACTOR_FUSION_I, "REACTOR_FUSION_I"},
        {ShipReactorSymbol::REACTOR_FISSION_I, "REACTOR_FISSION_I"},
        {ShipReactorSymbol::REACTOR_CHEMICAL_I, "REACTOR_CHEMICAL_I"},
        {ShipReactorSymbol::REACTOR_ANTIMATTER_I, "REACTOR_ANTIMATTER_I"},
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
    j.at("requirements").get_to(sf.requirements);
  }

 public:
  ShipReactorSymbol symbol{};
  std::string name;
  std::string description;
  std::optional<uint64_t> condition;
  uint64_t powerOutput = 0;
  ShipRequirements requirements{};
};