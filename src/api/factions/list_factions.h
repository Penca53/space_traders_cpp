#pragma once

#include <third_party/json.h>

#include "src/models/faction.h"
#include "src/models/meta.h"

struct ListFactionsRequest {
 public:
  uint64_t limit = 10;
  uint64_t page = 1;
};
struct ListFactionsResponse {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ListFactionsResponse, data, meta)

 public:
  std::vector<Faction> data;
  Meta meta;
};