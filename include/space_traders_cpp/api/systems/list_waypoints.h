#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/meta.h"
#include "space_traders_cpp/models/waypoint.h"
#include "space_traders_cpp/utility.h"

struct ListWaypointsRequest {
 public:
  struct PathParams {
    std::string systemSymbol;
  };
  struct QueryParams {
    uint64_t limit = 10;
    uint64_t page = 1;
  };
  struct Body {};

 public:
  explicit ListWaypointsRequest() = default;
  explicit ListWaypointsRequest(PathParams path_params,
                                QueryParams query_params, Body body);

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

struct ListWaypointsResponse {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ListWaypointsResponse, data, meta)

 public:
  static constexpr int32_t kValidStatus = kGetOkStatus;

 public:
  std::vector<Waypoint> data;
  Meta meta;
};
