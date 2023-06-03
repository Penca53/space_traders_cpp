#pragma once

#include "json.h"
#include "space_traders_cpp/models/meta.h"
#include "space_traders_cpp/models/system.h"

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