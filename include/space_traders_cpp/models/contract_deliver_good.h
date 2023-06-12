#pragma once

#include "nlohmann/json.hpp"

struct ContractDeliverGood {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ContractDeliverGood, tradeSymbol,
                                 destinationSymbol, unitsRequired,
                                 unitsFulfilled)

 public:
  bool operator==(const ContractDeliverGood&) const = default;

 public:
  std::string tradeSymbol;
  std::string destinationSymbol;
  uint64_t unitsRequired = 0;
  uint64_t unitsFulfilled = 0;
};