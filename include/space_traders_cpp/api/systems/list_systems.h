#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/meta.h"
#include "space_traders_cpp/models/system.h"
#include "space_traders_cpp/utility.h"

struct ListSystemsRequest {
 public:
  struct PathParams {};
  struct QueryParams {
    uint64_t limit = 10;
    uint64_t page = 1;
  };
  struct Body {};

 public:
  explicit ListSystemsRequest() = default;
  explicit ListSystemsRequest(PathParams path_params, QueryParams query_params,
                              Body body);

 public:
  std::string FormattedPath() const;
  httplib::Params HttplibParams() const;

 public:
  static const std::string kRelativePath;

 public:
  PathParams path_params{};
  QueryParams query_params{};
  Body body{};
};

struct ListSystemsResponse {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ListSystemsResponse, data, meta)

 public:
  static constexpr int32_t kValidStatus = kHttpOkStatus;

 public:
  int32_t http_status = 0;

 public:
  std::vector<System> data;
  Meta meta;
};
