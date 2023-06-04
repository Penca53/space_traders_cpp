#pragma once

#include "nlohmann/json.hpp"

enum class ShipRole {
  FABRICATOR,
  HARVESTER,
  HAULER,
  INTERCEPTOR,
  EXCAVATOR,
  TRANSPORT,
  REPAIR,
  SURVEYOR,
  COMMAND,
  CARRIER,
  PATROL,
  SATELLITE,
  EXPLORER,
  REFINERY,
};
NLOHMANN_JSON_SERIALIZE_ENUM(ShipRole,
                             {
                                 {ShipRole::FABRICATOR, "FABRICATOR"},
                                 {ShipRole::HARVESTER, "HARVESTER"},
                                 {ShipRole::HAULER, "HAULER"},
                                 {ShipRole::INTERCEPTOR, "INTERCEPTOR"},
                                 {ShipRole::EXCAVATOR, "EXCAVATOR"},
                                 {ShipRole::TRANSPORT, "TRANSPORT"},
                                 {ShipRole::REPAIR, "REPAIR"},
                                 {ShipRole::SURVEYOR, "SURVEYOR"},
                                 {ShipRole::COMMAND, "COMMAND"},
                                 {ShipRole::CARRIER, "CARRIER"},
                                 {ShipRole::PATROL, "PATROL"},
                                 {ShipRole::SATELLITE, "SATELLITE"},
                                 {ShipRole::EXPLORER, "EXPLORER"},
                                 {ShipRole::REFINERY, "REFINERY"},
                             })
