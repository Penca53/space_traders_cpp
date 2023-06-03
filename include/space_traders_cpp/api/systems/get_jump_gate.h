#pragma once

#include "json.h"
#include "space_traders_cpp/models/jump_gate.h"

struct GetJumpGateRequest {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(GetJumpGateRequest, systemSymbol,
                                 waypointSymbol)

 public:
  std::string systemSymbol;
  std::string waypointSymbol;
};
struct GetJumpGateResponse {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(GetJumpGateResponse, data)

 public:
  JumpGate data;
};