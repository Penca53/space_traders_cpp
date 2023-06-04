#pragma once

#include "nlohmann/json.hpp"

struct SurveyDeposit {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(SurveyDeposit, symbol)

 public:
  std::string symbol;
};