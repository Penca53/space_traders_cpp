#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/ship_fuel.h"
#include "space_traders_cpp/models/ship_nav.h"
#include "space_traders_cpp/utility.h"

struct WarpShipRequest {
 public:
  struct PathParams {
    std::string shipSymbol;
  };
  struct QueryParams {};
  struct Body {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Body, waypointSymbol)

   public:
    std::string waypointSymbol;
  };

 public:
  explicit WarpShipRequest() = default;
  explicit WarpShipRequest(PathParams path_params, QueryParams query_params,
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

struct WarpShipResponse {
 private:
  struct Data {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Data, fuel, nav)

   public:
    ShipFuel fuel{};
    ShipNav nav{};
  };

 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(WarpShipResponse, data)

 public:
  static constexpr int32_t kValidStatus = kHttpOkStatus;

 public:
  int32_t http_status = 0;

 public:
  Data data{};
};
