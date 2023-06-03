#pragma once

#include <third_party/json.h>

#include "src/models/agent.h"

struct MyAgentRequest {};

struct MyAgentResponse {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(MyAgentResponse, data)
 public:
  Agent data;
};