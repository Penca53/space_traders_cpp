#pragma once

#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/survey_deposit.h"

enum class SurveySize {
  kSmall,
  kModerate,
  kLarge,
};
NLOHMANN_JSON_SERIALIZE_ENUM(SurveySize,
                             {
                                 {SurveySize::kSmall, "SMALL"},
                                 {SurveySize::kModerate, "MODERATE"},
                                 {SurveySize::kLarge, "LARGE"},
                             })

struct Survey {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(Survey, signature, symbol, deposits,
                                 expiration, size)

 public:
  bool operator==(const Survey&) const = default;

 public:
  std::string signature;
  std::string symbol;
  std::vector<SurveyDeposit> deposits;
  std::chrono::system_clock::time_point expiration;
  SurveySize size{};
};