#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/ship_nav.h"
#include "space_traders_cpp/models/ship_nav_flight_mode.h"
#include "space_traders_cpp/utility.h"

struct PatchShipNavRequest {
 public:
  struct PathParams {
    std::string shipSymbol;
  };
  struct QueryParams {};
  struct Body {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Body, flightMode)

   public:
    ShipNavFlightMode flightMode{};
  };

 public:
  explicit PatchShipNavRequest() = default;
  explicit PatchShipNavRequest(PathParams path_params, QueryParams query_params,
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

struct PatchShipNavResponse {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(PatchShipNavResponse, data)

 public:
  static constexpr int32_t kValidStatus = kHttpOkStatus;

 public:
  ShipNav data{};
};
