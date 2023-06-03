#pragma once

#include <third_party/json.h>

struct Chart {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(Chart, waypointSymbol,
                                              submittedBy, submittedOn)
 public:
  std::optional<std::string> waypointSymbol;
  std::optional<std::string> submittedBy;
  std::optional<std::string> submittedOn;
};