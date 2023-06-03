#pragma once

#include "json.h"

#include "models/meta.h"
#include "models/system.h"

struct ListSystemsRequest {
 public:
  uint64_t limit = 10;
  uint64_t page = 1;
};
struct ListSystemsResponse {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ListSystemsResponse, data, meta)

 public:
  std::vector<System> data;
  Meta meta;
};