#pragma once

#include "nlohmann/json.hpp"

struct Meta {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(Meta, total, page, limit)

public:
  bool operator==(const Meta&) const = default;

 public:
  int64_t total = 0;
  int64_t page = 0;
  int64_t limit = 0;
};