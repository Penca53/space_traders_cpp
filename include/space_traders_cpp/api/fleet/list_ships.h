#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/meta.h"
#include "space_traders_cpp/models/ship.h"
#include "space_traders_cpp/utility.h"

struct ListShipsRequest {
 public:
  struct PathParams {};
  struct QueryParams {
    uint64_t limit = 10;
    uint64_t page = 1;
  };
  struct Body {};

 public:
  explicit ListShipsRequest() = default;
  explicit ListShipsRequest(PathParams path_params, QueryParams query_params,
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

struct ListShipsResponse {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ListShipsResponse, data, meta)

 public:
  static constexpr int32_t kValidStatus = kHttpOkStatus;

 public:
  std::vector<Ship> data;
  Meta meta;
};
