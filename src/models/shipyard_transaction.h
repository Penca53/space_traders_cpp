#pragma once

#include <third_party/json.h>

struct ShipyardTransaction {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShipyardTransaction, waypointSymbol,
                                 shipSymbol, price, agentSymbol, timestamp)

 public:
  std::string waypointSymbol;
  std::string shipSymbol;
  uint64_t price = 0;
  std::string agentSymbol;
  std::string timestamp;
};