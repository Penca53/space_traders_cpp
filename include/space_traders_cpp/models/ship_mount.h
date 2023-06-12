#pragma once

#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/ship_requirements.h"

enum class ShipMountSymbol {
  MOUNT_GAS_SIPHON_I,
  MOUNT_GAS_SIPHON_II,
  MOUNT_GAS_SIPHON_III,
  MOUNT_SURVEYOR_I,
  MOUNT_SURVEYOR_II,
  MOUNT_SURVEYOR_III,
  MOUNT_SENSOR_ARRAY_I,
  MOUNT_SENSOR_ARRAY_II,
  MOUNT_SENSOR_ARRAY_III,
  MOUNT_MINING_LASER_I,
  MOUNT_MINING_LASER_II,
  MOUNT_MINING_LASER_III,
  MOUNT_LASER_CANNON_I,
  MOUNT_MISSILE_LAUNCHER_I,
  MOUNT_TURRET_I,
};
NLOHMANN_JSON_SERIALIZE_ENUM(
    ShipMountSymbol,
    {
        {ShipMountSymbol::MOUNT_GAS_SIPHON_I, "MOUNT_GAS_SIPHON_I"},
        {ShipMountSymbol::MOUNT_GAS_SIPHON_II, "MOUNT_GAS_SIPHON_II"},
        {ShipMountSymbol::MOUNT_GAS_SIPHON_III, "MOUNT_GAS_SIPHON_III"},
        {ShipMountSymbol::MOUNT_SURVEYOR_I, "MOUNT_SURVEYOR_I"},
        {ShipMountSymbol::MOUNT_SURVEYOR_II, "MOUNT_SURVEYOR_II"},
        {ShipMountSymbol::MOUNT_SURVEYOR_III, "MOUNT_SURVEYOR_III"},
        {ShipMountSymbol::MOUNT_SENSOR_ARRAY_I, "MOUNT_SENSOR_ARRAY_I"},
        {ShipMountSymbol::MOUNT_SENSOR_ARRAY_II, "MOUNT_SENSOR_ARRAY_II"},
        {ShipMountSymbol::MOUNT_SENSOR_ARRAY_III, "MOUNT_SENSOR_ARRAY_III"},
        {ShipMountSymbol::MOUNT_MINING_LASER_I, "MOUNT_MINING_LASER_I"},
        {ShipMountSymbol::MOUNT_MINING_LASER_II, "MOUNT_MINING_LASER_II"},
        {ShipMountSymbol::MOUNT_MINING_LASER_III, "MOUNT_MINING_LASER_III"},
        {ShipMountSymbol::MOUNT_LASER_CANNON_I, "MOUNT_LASER_CANNON_I"},
        {ShipMountSymbol::MOUNT_MISSILE_LAUNCHER_I, "MOUNT_MISSILE_LAUNCHER_I"},
        {ShipMountSymbol::MOUNT_TURRET_I, "MOUNT_TURRET_I"},
    })

enum class ShipMountDeposit {
  QUARTZ_SAND,
  SILICON_CRYSTALS,
  PRECIOUS_STONES,
  ICE_WATER,
  AMMONIA_ICE,
  IRON_ORE,
  COPPER_ORE,
  SILVER_ORE,
  ALUMINUM_ORE,
  GOLD_ORE,
  PLATINUM_ORE,
  DIAMONDS,
  URANITE_ORE,
  MERITIUM_ORE,
};
NLOHMANN_JSON_SERIALIZE_ENUM(
    ShipMountDeposit,
    {
        {ShipMountDeposit::QUARTZ_SAND, "QUARTZ_SAND"},
        {ShipMountDeposit::SILICON_CRYSTALS, "SILICON_CRYSTALS"},
        {ShipMountDeposit::PRECIOUS_STONES, "PRECIOUS_STONES"},
        {ShipMountDeposit::ICE_WATER, "ICE_WATER"},
        {ShipMountDeposit::AMMONIA_ICE, "AMMONIA_ICE"},
        {ShipMountDeposit::IRON_ORE, "IRON_ORE"},
        {ShipMountDeposit::COPPER_ORE, "COPPER_ORE"},
        {ShipMountDeposit::SILVER_ORE, "SILVER_ORE"},
        {ShipMountDeposit::ALUMINUM_ORE, "ALUMINUM_ORE"},
        {ShipMountDeposit::GOLD_ORE, "GOLD_ORE"},
        {ShipMountDeposit::PLATINUM_ORE, "PLATINUM_ORE"},
        {ShipMountDeposit::DIAMONDS, "DIAMONDS"},
        {ShipMountDeposit::URANITE_ORE, "URANITE_ORE"},
        {ShipMountDeposit::MERITIUM_ORE, "MERITIUM_ORE"},
    })

struct ShipMount {
 public:
  friend void to_json(nlohmann::json& j, const ShipMount& sm) {
    j["symbol"] = sm.symbol;
    j["name"] = sm.name;
    j["description"] = sm.description;
    j["strength"] = sm.strength;
    j["deposits"] = sm.deposits;
    j["requirements"] = sm.requirements;
  }
  friend void from_json(const nlohmann::json& j, ShipMount& sm) {
    j.at("symbol").get_to(sm.symbol);
    j.at("name").get_to(sm.name);
    if (j.contains("description")) {
      j.at("description").get_to(sm.description);
    }
    if (j.contains("strength")) {
      j.at("strength").get_to(sm.strength);
    }
    if (j.contains("deposits")) {
      j.at("deposits").get_to(sm.deposits);
    }
    j.at("requirements").get_to(sm.requirements);
  }

 public:
  bool operator==(const ShipMount&) const = default;

 public:
  ShipMountSymbol symbol{};
  std::string name;
  std::optional<std::string> description;
  std::optional<uint64_t> strength;
  std::optional<std::vector<std::string>> deposits;
  ShipRequirements requirements{};
};