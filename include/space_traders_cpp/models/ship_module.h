#pragma once

#include "json.h"

#include "space_traders_cpp/models/ship_requirements.h"

enum class ShipModuleSymbol {
  MODULE_MINERAL_PROCESSOR_I,
  MODULE_CARGO_HOLD_I,
  MODULE_CREW_QUARTERS_I,
  MODULE_ENVOY_QUARTERS_I,
  MODULE_PASSENGER_CABIN_I,
  MODULE_MICRO_REFINERY_I,
  MODULE_ORE_REFINERY_I,
  MODULE_FUEL_REFINERY_I,
  MODULE_SCIENCE_LAB_I,
  MODULE_JUMP_DRIVE_I,
  MODULE_JUMP_DRIVE_II,
  MODULE_JUMP_DRIVE_III,
  MODULE_WARP_DRIVE_I,
  MODULE_WARP_DRIVE_II,
  MODULE_WARP_DRIVE_III,
  MODULE_SHIELD_GENERATOR_I,
  MODULE_SHIELD_GENERATOR_II,
};
NLOHMANN_JSON_SERIALIZE_ENUM(
    ShipModuleSymbol,
    {
        {ShipModuleSymbol::MODULE_MINERAL_PROCESSOR_I,
         "MODULE_MINERAL_PROCESSOR_I"},
        {ShipModuleSymbol::MODULE_CARGO_HOLD_I, "MODULE_CARGO_HOLD_I"},
        {ShipModuleSymbol::MODULE_CREW_QUARTERS_I, "MODULE_CREW_QUARTERS_I"},
        {ShipModuleSymbol::MODULE_ENVOY_QUARTERS_I, "MODULE_ENVOY_QUARTERS_I"},
        {ShipModuleSymbol::MODULE_PASSENGER_CABIN_I,
         "MODULE_PASSENGER_CABIN_I"},
        {ShipModuleSymbol::MODULE_MICRO_REFINERY_I, "MODULE_MICRO_REFINERY_I"},
        {ShipModuleSymbol::MODULE_ORE_REFINERY_I, "MODULE_ORE_REFINERY_I"},
        {ShipModuleSymbol::MODULE_FUEL_REFINERY_I, "MODULE_FUEL_REFINERY_I"},
        {ShipModuleSymbol::MODULE_SCIENCE_LAB_I, "MODULE_SCIENCE_LAB_I"},
        {ShipModuleSymbol::MODULE_JUMP_DRIVE_I, "MODULE_JUMP_DRIVE_I"},
        {ShipModuleSymbol::MODULE_JUMP_DRIVE_II, "MODULE_JUMP_DRIVE_II"},
        {ShipModuleSymbol::MODULE_JUMP_DRIVE_III, "MODULE_JUMP_DRIVE_III"},
        {ShipModuleSymbol::MODULE_WARP_DRIVE_I, "MODULE_WARP_DRIVE_I"},
        {ShipModuleSymbol::MODULE_WARP_DRIVE_II, "MODULE_WARP_DRIVE_II"},
        {ShipModuleSymbol::MODULE_WARP_DRIVE_III, "MODULE_WARP_DRIVE_III"},
        {ShipModuleSymbol::MODULE_SHIELD_GENERATOR_I,
         "MODULE_SHIELD_GENERATOR_I"},
        {ShipModuleSymbol::MODULE_SHIELD_GENERATOR_II,
         "MODULE_SHIELD_GENERATOR_II"},
    })

struct ShipModule {
 public:
  friend void to_json(nlohmann::json& j, const ShipModule& sm) {
    j["symbol"] = sm.symbol;
    j["capacity"] = sm.capacity;
    j["range"] = sm.range;
    j["name"] = sm.name;
    j["description"] = sm.description;
    j["requirements"] = sm.requirements;
  }
  friend void from_json(const nlohmann::json& j, ShipModule& sm) {
    j.at("symbol").get_to(sm.symbol);
    if (j.contains("capacity")) {
      j.at("capacity").get_to(sm.capacity);
    }
    if (j.contains("range")) {
      j.at("range").get_to(sm.range);
    }
    j.at("name").get_to(sm.name);
    if (j.contains("description")) {
      j.at("description").get_to(sm.description);
    }
    j.at("requirements").get_to(sm.requirements);
  }

 public:
  ShipModuleSymbol symbol{};
  std::optional<uint64_t> capacity;
  std::optional<uint64_t> range;
  std::string name;
  std::optional<std::string> description;
  ShipRequirements requirements{};
};