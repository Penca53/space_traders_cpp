#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/faction.h"
#include "space_traders_cpp/models/meta.h"
#include "space_traders_cpp/utility.h"

struct ListFactionsRequest {
 public:
  struct PathParams {};
  struct QueryParams {
    uint64_t limit = 10;
    uint64_t page = 1;
  };
  struct Body {};

 public:
  explicit ListFactionsRequest() = default;
  explicit ListFactionsRequest(PathParams path_params, QueryParams query_params,
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

struct ListFactionsResponse {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ListFactionsResponse, data, meta)

 public:
  bool operator==(const ListFactionsResponse&) const = default;

 public:
  static constexpr int32_t kValidStatus = kHttpOkStatus;

 public:
  std::vector<Faction> data;
  Meta meta;
  int32_t http_status = 0;
};
