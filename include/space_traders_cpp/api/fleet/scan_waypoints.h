#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/cooldown.h"
#include "space_traders_cpp/models/scanned_waypoint.h"
#include "space_traders_cpp/utility.h"

struct ScanWaypointsRequest {
 public:
  struct PathParams {
    std::string shipSymbol;
  };
  struct QueryParams {};
  struct Body {};

 public:
  explicit ScanWaypointsRequest() = default;
  explicit ScanWaypointsRequest(PathParams path_params,
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

struct ScanWaypointsResponse {
 private:
  struct Data {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Data, cooldown, waypoints)

   public:
    Cooldown cooldown{};
    std::vector<ScannedWaypoint> waypoints{};
  };

 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ScanWaypointsResponse, data)

 public:
  static constexpr int32_t kValidStatus = kHttpCreatedStatus;

 public:
  Data data{};
};
