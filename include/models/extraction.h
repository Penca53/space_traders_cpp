#pragma once

#include "json.h"

#include "models/extraction_yield.h"

struct Extraction {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(Extraction, shipSymbol, yield)

 public:
  std::string shipSymbol;
  ExtractionYield yield{};
};