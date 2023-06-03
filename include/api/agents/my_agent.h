#pragma once

#include "json.h"
#include "models/agent.h"

struct MyAgentRequest {};

struct MyAgentResponse {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(MyAgentResponse, data)
 public:
  Agent data;
};