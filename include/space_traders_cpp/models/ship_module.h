#pragma once

#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/ship_requirements.h"
#include "space_traders_cpp/utility.h"

enum class ShipModuleSymbol {
  kModuleMineralProcessorI,
  kModuleCargoHoldI,
  kModuleCrewQuartersI,
  kModuleEnvoyQuartersI,
  kModulePassengerCabinI,
  kModuleMicroRefineryI,
  kModuleOreRefineryI,
  kModuleFuelRefineryI,
  kModuleScienceLabI,
  kModuleJumpDriveI,
  kModuleJumpDriveIi,
  kModuleJumpDriveIii,
  kModuleWarpDriveI,
  kModuleWarpDriveIi,
  kModuleWarpDriveIii,
  kModuleShieldGeneratorI,
  kModuleShieldGeneratorIi,
};
NLOHMANN_JSON_SERIALIZE_ENUM(
    ShipModuleSymbol,
    {
        {ShipModuleSymbol::kModuleMineralProcessorI,
         "MODULE_MINERAL_PROCESSOR_I"},
        {ShipModuleSymbol::kModuleCargoHoldI, "MODULE_CARGO_HOLD_I"},
        {ShipModuleSymbol::kModuleCrewQuartersI, "MODULE_CREW_QUARTERS_I"},
        {ShipModuleSymbol::kModuleEnvoyQuartersI, "MODULE_ENVOY_QUARTERS_I"},
        {ShipModuleSymbol::kModulePassengerCabinI, "MODULE_PASSENGER_CABIN_I"},
        {ShipModuleSymbol::kModuleMicroRefineryI, "MODULE_MICRO_REFINERY_I"},
        {ShipModuleSymbol::kModuleOreRefineryI, "MODULE_ORE_REFINERY_I"},
        {ShipModuleSymbol::kModuleFuelRefineryI, "MODULE_FUEL_REFINERY_I"},
        {ShipModuleSymbol::kModuleScienceLabI, "MODULE_SCIENCE_LAB_I"},
        {ShipModuleSymbol::kModuleJumpDriveI, "MODULE_JUMP_DRIVE_I"},
        {ShipModuleSymbol::kModuleJumpDriveIi, "MODULE_JUMP_DRIVE_II"},
        {ShipModuleSymbol::kModuleJumpDriveIii, "MODULE_JUMP_DRIVE_III"},
        {ShipModuleSymbol::kModuleWarpDriveI, "MODULE_WARP_DRIVE_I"},
        {ShipModuleSymbol::kModuleWarpDriveIi, "MODULE_WARP_DRIVE_II"},
        {ShipModuleSymbol::kModuleWarpDriveIii, "MODULE_WARP_DRIVE_III"},
        {ShipModuleSymbol::kModuleShieldGeneratorI,
         "MODULE_SHIELD_GENERATOR_I"},
        {ShipModuleSymbol::kModuleShieldGeneratorIi,
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
  bool operator==(const ShipModule&) const = default;

 public:
  ShipModuleSymbol symbol{};
  std::optional<uint64_t> capacity;
  std::optional<uint64_t> range;
  std::string name;
  std::optional<std::string> description;
  ShipRequirements requirements{};
};