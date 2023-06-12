#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/ship_fuel.h"
#include "space_traders_cpp/models/ship_nav.h"
#include "space_traders_cpp/utility.h"

struct NavigateShipRequest {
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
  explicit NavigateShipRequest() = default;
  explicit NavigateShipRequest(PathParams path_params, QueryParams query_params,
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

struct NavigateShipResponse {
 private:
  struct Data {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Data, fuel, nav)

   public:
    bool operator==(const Data&) const = default;

   public:
    ShipFuel fuel{};
    ShipNav nav{};
  };

 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(NavigateShipResponse, data)

 public:
  bool operator==(const NavigateShipResponse&) const = default;

 public:
  static constexpr int32_t kValidStatus = kHttpOkStatus;

 public:
  Data data{};
  int32_t http_status = 0;
};
