#pragma once

#include "nlohmann/json.hpp"

enum class ShipType {
  kShipProbe,
  kShipMiningDrone,
  kShipInterceptor,
  kShipLightHauler,
  kShipCommandFrigate,
  kShipExplorer,
  kShipHeavyFreighter,
  kShipLightShuttle,
  kShipOreHound,
  kShipRefiningFreighter,
};
NLOHMANN_JSON_SERIALIZE_ENUM(
    ShipType, {
                  {ShipType::kShipProbe, "SHIP_PROBE"},
                  {ShipType::kShipMiningDrone, "SHIP_MINING_DRONE"},
                  {ShipType::kShipInterceptor, "SHIP_INTERCEPTOR"},
                  {ShipType::kShipLightHauler, "SHIP_LIGHT_HAULER"},
                  {ShipType::kShipCommandFrigate, "SHIP_COMMAND_FRIGATE"},
                  {ShipType::kShipExplorer, "SHIP_EXPLORER"},
                  {ShipType::kShipHeavyFreighter, "SHIP_HEAVY_FREIGHTER"},
                  {ShipType::kShipLightShuttle, "SHIP_LIGHT_SHUTTLE"},
                  {ShipType::kShipOreHound, "SHIP_ORE_HOUND"},
                  {ShipType::kShipRefiningFreighter, "SHIP_REFINING_FREIGHTER"},
              })
