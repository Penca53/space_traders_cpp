#pragma once

#include "json.h"

enum class WaypointTraitSymbol {
  UNCHARTED,
  MARKETPLACE,
  SHIPYARD,
  OUTPOST,
  SCATTERED_SETTLEMENTS,
  SPRAWLING_CITIES,
  MEGA_STRUCTURES,
  OVERCROWDED,
  HIGH_TECH,
  CORRUPT,
  BUREAUCRATIC,
  TRADING_HUB,
  INDUSTRIAL,
  BLACK_MARKET,
  RESEARCH_FACILITY,
  MILITARY_BASE,
  SURVEILLANCE_OUTPOST,
  EXPLORATION_OUTPOST,
  MINERAL_DEPOSITS,
  COMMON_METAL_DEPOSITS,
  PRECIOUS_METAL_DEPOSITS,
  RARE_METAL_DEPOSITS,
  METHANE_POOLS,
  ICE_CRYSTALS,
  EXPLOSIVE_GASES,
  STRONG_MAGNETOSPHERE,
  VIBRANT_AURORAS,
  SALT_FLATS,
  CANYONS,
  PERPETUAL_DAYLIGHT,
  PERPETUAL_OVERCAST,
  DRY_SEABEDS,
  MAGMA_SEAS,
  SUPERVOLCANOES,
  ASH_CLOUDS,
  VAST_RUINS,
  MUTATED_FLORA,
  TERRAFORMED,
  EXTREME_TEMPERATURES,
  EXTREME_PRESSURE,
  DIVERSE_LIFE,
  SCARCE_LIFE,
  FOSSILS,
  WEAK_GRAVITY,
  STRONG_GRAVITY,
  CRUSHING_GRAVITY,
  TOXIC_ATMOSPHERE,
  CORROSIVE_ATMOSPHERE,
  BREATHABLE_ATMOSPHERE,
  JOVIAN,
  ROCKY,
  VOLCANIC,
  FROZEN,
  SWAMP,
  BARREN,
  TEMPERATE,
  JUNGLE,
  OCEAN,
  STRIPPED,
};
NLOHMANN_JSON_SERIALIZE_ENUM(
    WaypointTraitSymbol,
    {
        {WaypointTraitSymbol::UNCHARTED, "UNCHARTED"},
        {WaypointTraitSymbol::MARKETPLACE, "MARKETPLACE"},
        {WaypointTraitSymbol::SHIPYARD, "SHIPYARD"},
        {WaypointTraitSymbol::OUTPOST, "OUTPOST"},
        {WaypointTraitSymbol::SCATTERED_SETTLEMENTS, "SCATTERED_SETTLEMENTS"},
        {WaypointTraitSymbol::SPRAWLING_CITIES, "SPRAWLING_CITIES"},
        {WaypointTraitSymbol::MEGA_STRUCTURES, "MEGA_STRUCTURES"},
        {WaypointTraitSymbol::OVERCROWDED, "OVERCROWDED"},
        {WaypointTraitSymbol::HIGH_TECH, "HIGH_TECH"},
        {WaypointTraitSymbol::CORRUPT, "CORRUPT"},
        {WaypointTraitSymbol::BUREAUCRATIC, "BUREAUCRATIC"},
        {WaypointTraitSymbol::TRADING_HUB, "TRADING_HUB"},
        {WaypointTraitSymbol::INDUSTRIAL, "INDUSTRIAL"},
        {WaypointTraitSymbol::BLACK_MARKET, "BLACK_MARKET"},
        {WaypointTraitSymbol::RESEARCH_FACILITY, "RESEARCH_FACILITY"},
        {WaypointTraitSymbol::MILITARY_BASE, "MILITARY_BASE"},
        {WaypointTraitSymbol::SURVEILLANCE_OUTPOST, "SURVEILLANCE_OUTPOST"},
        {WaypointTraitSymbol::EXPLORATION_OUTPOST, "EXPLORATION_OUTPOST"},
        {WaypointTraitSymbol::MINERAL_DEPOSITS, "MINERAL_DEPOSITS"},
        {WaypointTraitSymbol::COMMON_METAL_DEPOSITS, "COMMON_METAL_DEPOSITS"},
        {WaypointTraitSymbol::PRECIOUS_METAL_DEPOSITS,
         "PRECIOUS_METAL_DEPOSITS"},
        {WaypointTraitSymbol::RARE_METAL_DEPOSITS, "RARE_METAL_DEPOSITS"},
        {WaypointTraitSymbol::METHANE_POOLS, "METHANE_POOLS"},
        {WaypointTraitSymbol::ICE_CRYSTALS, "ICE_CRYSTALS"},
        {WaypointTraitSymbol::EXPLOSIVE_GASES, "EXPLOSIVE_GASES"},
        {WaypointTraitSymbol::STRONG_MAGNETOSPHERE, "STRONG_MAGNETOSPHERE"},
        {WaypointTraitSymbol::VIBRANT_AURORAS, "VIBRANT_AURORAS"},
        {WaypointTraitSymbol::SALT_FLATS, "SALT_FLATS"},
        {WaypointTraitSymbol::CANYONS, "CANYONS"},
        {WaypointTraitSymbol::PERPETUAL_DAYLIGHT, "PERPETUAL_DAYLIGHT"},
        {WaypointTraitSymbol::PERPETUAL_OVERCAST, "PERPETUAL_OVERCAST"},
        {WaypointTraitSymbol::DRY_SEABEDS, "DRY_SEABEDS"},
        {WaypointTraitSymbol::MAGMA_SEAS, "MAGMA_SEAS"},
        {WaypointTraitSymbol::SUPERVOLCANOES, "SUPERVOLCANOES"},
        {WaypointTraitSymbol::ASH_CLOUDS, "ASH_CLOUDS"},
        {WaypointTraitSymbol::VAST_RUINS, "VAST_RUINS"},
        {WaypointTraitSymbol::MUTATED_FLORA, "MUTATED_FLORA"},
        {WaypointTraitSymbol::TERRAFORMED, "TERRAFORMED"},
        {WaypointTraitSymbol::EXTREME_TEMPERATURES, "EXTREME_TEMPERATURES"},
        {WaypointTraitSymbol::EXTREME_PRESSURE, "EXTREME_PRESSURE"},
        {WaypointTraitSymbol::DIVERSE_LIFE, "DIVERSE_LIFE"},
        {WaypointTraitSymbol::SCARCE_LIFE, "SCARCE_LIFE"},
        {WaypointTraitSymbol::FOSSILS, "FOSSILS"},
        {WaypointTraitSymbol::WEAK_GRAVITY, "WEAK_GRAVITY"},
        {WaypointTraitSymbol::STRONG_GRAVITY, "STRONG_GRAVITY"},
        {WaypointTraitSymbol::CRUSHING_GRAVITY, "CRUSHING_GRAVITY"},
        {WaypointTraitSymbol::TOXIC_ATMOSPHERE, "TOXIC_ATMOSPHERE"},
        {WaypointTraitSymbol::CORROSIVE_ATMOSPHERE, "CORROSIVE_ATMOSPHERE"},
        {WaypointTraitSymbol::BREATHABLE_ATMOSPHERE, "BREATHABLE_ATMOSPHERE"},
        {WaypointTraitSymbol::JOVIAN, "JOVIAN"},
        {WaypointTraitSymbol::ROCKY, "ROCKY"},
        {WaypointTraitSymbol::VOLCANIC, "VOLCANIC"},
        {WaypointTraitSymbol::FROZEN, "FROZEN"},
        {WaypointTraitSymbol::SWAMP, "SWAMP"},
        {WaypointTraitSymbol::BARREN, "BARREN"},
        {WaypointTraitSymbol::TEMPERATE, "TEMPERATE"},
        {WaypointTraitSymbol::JUNGLE, "JUNGLE"},
        {WaypointTraitSymbol::OCEAN, "OCEAN"},
        {WaypointTraitSymbol::STRIPPED, "STRIPPED"},
    })

struct WaypointTrait {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(WaypointTrait, symbol, name, description)

 public:
  WaypointTraitSymbol symbol{};
  std::string name;
  std::string description;
};