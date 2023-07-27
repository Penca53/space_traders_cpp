#pragma once

#include "httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/ship.h"
#include "space_traders_cpp/utility.h"

struct GetShipNavRequest {
 public:
  struct PathParams {
    std::string shipSymbol;
  };
  struct QueryParams {};
  struct Body {};

 public:
  explicit GetShipNavRequest() = default;
  explicit GetShipNavRequest(PathParams path_params, QueryParams query_params,
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

struct GetShipNavResponse {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(GetShipNavResponse, data)

 public:
  bool operator==(const GetShipNavResponse&) const = default;

 public:
  static constexpr int32_t kValidStatus = kHttpOkStatus;

 public:
  ShipNav data{};
  int32_t http_status = 0;
};
