#pragma once

#include "json.h"

#include "models/faction.h"
#include "models/meta.h"

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