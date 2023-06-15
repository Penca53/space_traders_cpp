#pragma once

#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/ship_requirements.h"

enum class ShipMountSymbol {
  kMountGasSiphonI,
  kMountGasSiphonIi,
  kMountGasSiphonIii,
  kMountSurveyorI,
  kMountSurveyorIi,
  kMountSurveyorIii,
  kMountSensorArrayI,
  kMountSensorArrayIi,
  kMountSensorArrayIii,
  kMountMiningLaserI,
  kMountMiningLaserIi,
  kMountMiningLaserIii,
  kMountLaserCannonI,
  kMountMissileLauncherI,
  kMountTurretI,
};
NLOHMANN_JSON_SERIALIZE_ENUM(
    ShipMountSymbol,
    {
        {ShipMountSymbol::kMountGasSiphonI, "MOUNT_GAS_SIPHON_I"},
        {ShipMountSymbol::kMountGasSiphonIi, "MOUNT_GAS_SIPHON_II"},
        {ShipMountSymbol::kMountGasSiphonIii, "MOUNT_GAS_SIPHON_III"},
        {ShipMountSymbol::kMountSurveyorI, "MOUNT_SURVEYOR_I"},
        {ShipMountSymbol::kMountSurveyorIi, "MOUNT_SURVEYOR_II"},
        {ShipMountSymbol::kMountSurveyorIii, "MOUNT_SURVEYOR_III"},
        {ShipMountSymbol::kMountSensorArrayI, "MOUNT_SENSOR_ARRAY_I"},
        {ShipMountSymbol::kMountSensorArrayIi, "MOUNT_SENSOR_ARRAY_II"},
        {ShipMountSymbol::kMountSensorArrayIii, "MOUNT_SENSOR_ARRAY_III"},
        {ShipMountSymbol::kMountMiningLaserI, "MOUNT_MINING_LASER_I"},
        {ShipMountSymbol::kMountMiningLaserIi, "MOUNT_MINING_LASER_II"},
        {ShipMountSymbol::kMountMiningLaserIii, "MOUNT_MINING_LASER_III"},
        {ShipMountSymbol::kMountLaserCannonI, "MOUNT_LASER_CANNON_I"},
        {ShipMountSymbol::kMountMissileLauncherI, "MOUNT_MISSILE_LAUNCHER_I"},
        {ShipMountSymbol::kMountTurretI, "MOUNT_TURRET_I"},
    })

enum class ShipMountDeposit {
  kQuartzSand,
  kSiliconCrystals,
  kPreciousStones,
  kIceWater,
  kAmmoniaIce,
  kIronOre,
  kCopperOre,
  kSilverOre,
  kAluminumOre,
  kGoldOre,
  kPlatinumOre,
  kDiamonds,
  kUraniteOre,
  kMeritiumOre,
};
NLOHMANN_JSON_SERIALIZE_ENUM(
    ShipMountDeposit,
    {
        {ShipMountDeposit::kQuartzSand, "QUARTZ_SAND"},
        {ShipMountDeposit::kSiliconCrystals, "SILICON_CRYSTALS"},
        {ShipMountDeposit::kPreciousStones, "PRECIOUS_STONES"},
        {ShipMountDeposit::kIceWater, "ICE_WATER"},
        {ShipMountDeposit::kAmmoniaIce, "AMMONIA_ICE"},
        {ShipMountDeposit::kIronOre, "IRON_ORE"},
        {ShipMountDeposit::kCopperOre, "COPPER_ORE"},
        {ShipMountDeposit::kSilverOre, "SILVER_ORE"},
        {ShipMountDeposit::kAluminumOre, "ALUMINUM_ORE"},
        {ShipMountDeposit::kGoldOre, "GOLD_ORE"},
        {ShipMountDeposit::kPlatinumOre, "PLATINUM_ORE"},
        {ShipMountDeposit::kDiamonds, "DIAMONDS"},
        {ShipMountDeposit::kUraniteOre, "URANITE_ORE"},
        {ShipMountDeposit::kMeritiumOre, "MERITIUM_ORE"},
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