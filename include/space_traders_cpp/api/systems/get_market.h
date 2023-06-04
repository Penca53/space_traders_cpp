#pragma once

#include "json.h"
#include "space_traders_cpp/models/market.h"

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