#pragma once

#include "httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/ship_cargo.h"
#include "space_traders_cpp/utility.h"

struct GetShipCargoRequest {
 public:
  struct PathParams {
    std::string shipSymbol;
  };
  struct QueryParams {};
  struct Body {};

 public:
  explicit GetShipCargoRequest() = default;
  explicit GetShipCargoRequest(PathParams path_params, QueryParams query_params,
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

struct GetShipCargoResponse {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(GetShipCargoResponse, data)

 public:
  bool operator==(const GetShipCargoResponse&) const = default;

 public:
  static constexpr int32_t kValidStatus = kHttpOkStatus;

 public:
  ShipCargo data{};
  int32_t http_status = 0;
};
