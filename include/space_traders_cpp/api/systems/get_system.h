#pragma once

#include "json.h"
#include "space_traders_cpp/models/system.h"

struct GetSystemRequest {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(GetSystemRequest, systemSymbol)

 public:
  std::string systemSymbol;
};
struct GetSystemResponse {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(GetSystemResponse, data)

 public:
  System data;
};