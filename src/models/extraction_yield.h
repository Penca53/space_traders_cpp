#pragma once

#include <third_party/json.h>

struct ExtractionYield {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ExtractionYield, symbol, units)

 public:
  std::string symbol;
  int64_t units = 0;
};