#pragma once

#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/extraction_yield.h"

struct Extraction {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(Extraction, shipSymbol, yield)

 public:
  bool operator==(const Extraction&) const = default;

 public:
  std::string shipSymbol;
  ExtractionYield yield{};
};