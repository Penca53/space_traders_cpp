#pragma once

#include <third_party/json.h>

#include "src/models/meta.h"
#include "src/models/system.h"

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