#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/waypoint.h"
#include "space_traders_cpp/utility.h"

struct GetWaypointRequest {
 public:
  struct PathParams {
    std::string systemSymbol;
    std::string waypointSymbol;
  };
  struct QueryParams {};
  struct Body {};

 public:
  explicit GetWaypointRequest() = default;
  explicit GetWaypointRequest(PathParams path_params, QueryParams query_params,
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

struct GetWaypointResponse {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(GetWaypointResponse, data)

 public:
  static constexpr int32_t kValidStatus = kGetOkStatus;

 public:
  Waypoint data{};
};
