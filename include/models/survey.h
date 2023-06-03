#pragma once

#include "json.h"

#include "models/survey_deposit.h"

enum class SurveySize {
  SMALL,
  MODERATE,
  LARGE,
};
NLOHMANN_JSON_SERIALIZE_ENUM(SurveySize, {
                                             {SurveySize::SMALL, "SMALL"},
                                             {SurveySize::MODERATE, "MODERATE"},
                                             {SurveySize::LARGE, "LARGE"},
                                         })

struct Survey {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(Survey, signature, symbol, deposits,
                                 expiration, size)

 public:
  std::string signature;
  std::string symbol;
  std::vector<SurveyDeposit> deposits;
  std::string expiration;
  SurveySize size{};
};