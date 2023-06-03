#pragma once

#include <third_party/json.h>

struct SurveyDeposit {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(SurveyDeposit, symbol)

 public:
  std::string symbol;
};