#pragma once

#include "nlohmann/json.hpp"
#include "space_traders_cpp/utility.h"

struct Chart {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(Chart, waypointSymbol,
                                              submittedBy, submittedOn)

 public:
  bool operator==(const Chart&) const = default;

 public:
  std::optional<std::string> waypointSymbol;
  std::optional<std::string> submittedBy;
  std::optional<DateTime> submittedOn;
};