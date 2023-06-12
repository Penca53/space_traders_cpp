#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/cooldown.h"
#include "space_traders_cpp/utility.h"

struct GetShipCooldownRequest {
 public:
  struct PathParams {
    std::string shipSymbol;
  };
  struct QueryParams {};
  struct Body {};

 public:
  explicit GetShipCooldownRequest() = default;
  explicit GetShipCooldownRequest(PathParams path_params,
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

struct GetShipCooldownResponse {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(GetShipCooldownResponse, data)

 public:
  bool operator==(const GetShipCooldownResponse&) const = default;

 public:
  static constexpr int32_t kValidStatus = kHttpOkStatus;
  static constexpr int32_t kNoCooldownStatus = kHttpNoContentStatus;

 public:
  Cooldown data{};
  int32_t http_status = 0;
};
