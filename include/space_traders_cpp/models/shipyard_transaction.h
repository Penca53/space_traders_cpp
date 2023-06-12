#pragma once

#include "nlohmann/json.hpp"

struct ShipyardTransaction {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShipyardTransaction, waypointSymbol,
                                 shipSymbol, price, agentSymbol, timestamp)

 public:
  bool operator==(const ShipyardTransaction&) const = default;

 public:
  std::string waypointSymbol;
  std::string shipSymbol;
  uint64_t price = 0;
  std::string agentSymbol;
  std::string timestamp;
};