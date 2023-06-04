#pragma once

#include "nlohmann/json.hpp"

struct ContractPayment {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ContractPayment, onAccepted, onFulfilled)

 public:
  uint64_t onAccepted = 0;
  uint64_t onFulfilled = 0;
};