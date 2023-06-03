#pragma once

#include <third_party/json.h>

struct Meta {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(Meta, total, page, limit)

 public:
  int64_t total = 0;
  int64_t page = 0;
  int64_t limit = 0;
};