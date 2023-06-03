#pragma once

#include "json.h"

#include "models/agent.h"
#include "models/contract.h"
#include "models/faction.h"
#include "utility.h"

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
