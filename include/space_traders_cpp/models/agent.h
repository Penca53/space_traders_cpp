#pragma once

#include "json.h"

struct Agent {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(Agent, accountId, symbol, headquarters,
                                 credits, startingFaction)
 public:
  std::string accountId;
  std::string symbol;
  std::string headquarters;
  int64_t credits = 0;
  std::string startingFaction;
};
