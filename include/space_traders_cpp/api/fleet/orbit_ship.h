#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/ship_nav.h"
#include "space_traders_cpp/utility.h"

struct OrbitShipRequest {
 public:
  struct PathParams {
    std::string shipSymbol;
  };
  struct QueryParams {};
  struct Body {};

 public:
  explicit OrbitShipRequest() = default;
  explicit OrbitShipRequest(PathParams path_params, QueryParams query_params,
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

struct OrbitShipResponse {
  struct Data {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Data, nav)

   public:
    ShipNav nav{};
  };

 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(OrbitShipResponse, data)

 public:
  static constexpr int32_t kValidStatus = kHttpOkStatus;

 public:
  Data data{};
};
