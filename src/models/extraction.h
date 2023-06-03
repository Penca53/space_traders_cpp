#pragma once

#include <third_party/json.h>

#include "src/models/extraction_yield.h"

struct Extraction {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(Extraction, shipSymbol, yield)

 public:
  std::string shipSymbol;
  ExtractionYield yield{};
};