#pragma once

#include "httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/ship_mount.h"
#include "space_traders_cpp/utility.h"

struct GetMountsRequest {
 public:
  struct PathParams {
    std::string shipSymbol;
  };
  struct QueryParams {};
  struct Body {};

 public:
  explicit GetMountsRequest() = default;
  explicit GetMountsRequest(PathParams path_params, QueryParams query_params,
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

struct GetMountsResponse {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(GetMountsResponse, data)

 public:
  bool operator==(const GetMountsResponse&) const = default;

 public:
  static constexpr int32_t kValidStatus = kHttpOkStatus;

 public:
  std::vector<ShipMount> data;
  int32_t http_status = 0;
};
