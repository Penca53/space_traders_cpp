#pragma once

#include "httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/shipyard.h"
#include "space_traders_cpp/utility.h"

struct GetShipyardRequest {
 public:
  struct PathParams {
    std::string systemSymbol;
    std::string waypointSymbol;
  };
  struct QueryParams {};
  struct Body {};

 public:
  explicit GetShipyardRequest() = default;
  explicit GetShipyardRequest(PathParams path_params, QueryParams query_params,
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

struct GetShipyardResponse {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(GetShipyardResponse, data)

 public:
  bool operator==(const GetShipyardResponse&) const = default;

 public:
  static constexpr int32_t kValidStatus = kHttpOkStatus;

 public:
  Shipyard data{};
  int32_t http_status = 0;
};
