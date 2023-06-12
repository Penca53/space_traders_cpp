#pragma once

#include "nlohmann/json.hpp"

struct ExtractionYield {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ExtractionYield, symbol, units)

 public:
  bool operator==(const ExtractionYield&) const = default;

 public:
  std::string symbol;
  int64_t units = 0;
};