#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/ship_nav.h"
#include "space_traders_cpp/utility.h"

struct DockShipRequest {
 public:
  struct PathParams {
    std::string shipSymbol;
  };
  struct QueryParams {};
  struct Body {};

 public:
  explicit DockShipRequest() = default;
  explicit DockShipRequest(PathParams path_params, QueryParams query_params,
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

struct DockShipResponse {
 private:
  struct Data {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Data, nav)

   public:
    ShipNav nav{};
  };

 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(DockShipResponse, data)

 public:
  static constexpr int32_t kValidStatus = kHttpOkStatus;

 public:
  int32_t http_status = 0;

 public:
  Data data{};
};
