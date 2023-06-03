#pragma once

#include "json.h"
#include "space_traders_cpp/models/agent.h"
#include "space_traders_cpp/models/contract.h"
#include "space_traders_cpp/models/faction.h"
#include "space_traders_cpp/utility.h"

struct RegisterRequest {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(RegisterRequest, faction, symbol,
                                              email)

 public:
  std::string faction;
  std::string symbol;
  std::optional<std::string> email;
};
struct RegisterResponse {
  struct RegisterData {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(RegisterData, agent, contract, faction,
                                   token)
   public:
    Agent agent;
    Contract contract;
    Faction faction;
    std::string token;
  };

 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(RegisterResponse, data)

 public:
  RegisterData data;
};
