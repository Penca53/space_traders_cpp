#pragma once

#include "httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/chart.h"
#include "space_traders_cpp/models/waypoint.h"
#include "space_traders_cpp/utility.h"

struct CreateChartRequest {
 public:
  struct PathParams {
    std::string shipSymbol;
  };
  struct QueryParams {};
  struct Body {};

 public:
  explicit CreateChartRequest() = default;
  explicit CreateChartRequest(PathParams path_params, QueryParams query_params,
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

struct CreateChartResponse {
  struct Data {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Data, chart, waypoint)

   public:
    bool operator==(const Data&) const = default;

   public:
    Chart chart{};
    Waypoint waypoint{};
  };

 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(CreateChartResponse, data)

 public:
  bool operator==(const CreateChartResponse&) const = default;

 public:
  static constexpr int32_t kValidStatus = kHttpCreatedStatus;

 public:
  Data data{};
  int32_t http_status = 0;
};
