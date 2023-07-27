#pragma once

#include "httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/jump_gate.h"
#include "space_traders_cpp/utility.h"

struct GetJumpGateRequest {
 public:
  struct PathParams {
    std::string systemSymbol;
    std::string waypointSymbol;
  };
  struct QueryParams {};
  struct Body {};

 public:
  explicit GetJumpGateRequest() = default;
  explicit GetJumpGateRequest(PathParams path_params, QueryParams query_params,
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

struct GetJumpGateResponse {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(GetJumpGateResponse, data)

 public:
  bool operator==(const GetJumpGateResponse&) const = default;

 public:
  static constexpr int32_t kValidStatus = kHttpOkStatus;

 public:
  JumpGate data{};
  int32_t http_status = 0;
};
