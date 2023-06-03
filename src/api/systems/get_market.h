#pragma once

#include <third_party/json.h>

#include "src/models/market.h"

struct GetMarketRequest {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(GetMarketRequest, systemSymbol, waypointSymbol)

 public:
  std::string systemSymbol;
  std::string waypointSymbol;
};
struct GetMarketResponse {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(GetMarketResponse, data)

 public:
  Market data;
};