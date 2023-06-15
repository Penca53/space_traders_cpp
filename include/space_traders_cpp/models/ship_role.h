#pragma once

#include "nlohmann/json.hpp"

enum class ShipRole {
  kFabricator,
  kHarvester,
  kHauler,
  kInterceptor,
  kExcavator,
  kTransport,
  kRepair,
  kSurveyor,
  kCommand,
  kCarrier,
  kPatrol,
  kSatellite,
  kExplorer,
  kRefinery,
};
NLOHMANN_JSON_SERIALIZE_ENUM(ShipRole,
                             {
                                 {ShipRole::kFabricator, "FABRICATOR"},
                                 {ShipRole::kHarvester, "HARVESTER"},
                                 {ShipRole::kHauler, "HAULER"},
                                 {ShipRole::kInterceptor, "INTERCEPTOR"},
                                 {ShipRole::kExcavator, "EXCAVATOR"},
                                 {ShipRole::kTransport, "TRANSPORT"},
                                 {ShipRole::kRepair, "REPAIR"},
                                 {ShipRole::kSurveyor, "SURVEYOR"},
                                 {ShipRole::kCommand, "COMMAND"},
                                 {ShipRole::kCarrier, "CARRIER"},
                                 {ShipRole::kPatrol, "PATROL"},
                                 {ShipRole::kSatellite, "SATELLITE"},
                                 {ShipRole::kExplorer, "EXPLORER"},
                                 {ShipRole::kRefinery, "REFINERY"},
                             })
