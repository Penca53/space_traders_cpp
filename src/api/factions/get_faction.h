#pragma once

#include <third_party/json.h>

#include "src/models/faction.h"
#include "src/models/meta.h"

struct GetFactionRequest {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(GetFactionRequest, factionSymbol)

 public:
  std::string factionSymbol;
};
struct GetFactionResponse {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(GetFactionResponse, data)

 public:
  Faction data;
};