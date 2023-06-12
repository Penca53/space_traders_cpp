#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/ship.h"
#include "space_traders_cpp/utility.h"

struct GetShipRequest {
 public:
  struct PathParams {
    std::string shipSymbol;
  };
  struct QueryParams {};
  struct Body {};

 public:
  explicit GetShipRequest() = default;
  explicit GetShipRequest(PathParams path_params, QueryParams query_params,
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

struct GetShipResponse {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(GetShipResponse, data)

 public:
  bool operator==(const GetShipResponse&) const = default;

 public:
  static constexpr int32_t kValidStatus = kHttpOkStatus;

 public:
  Ship data{};
  int32_t http_status = 0;
};
