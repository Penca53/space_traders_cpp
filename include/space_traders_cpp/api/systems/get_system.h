#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/system.h"
#include "space_traders_cpp/utility.h"

struct GetSystemRequest {
 public:
  struct PathParams {
    std::string systemSymbol;
  };
  struct QueryParams {};
  struct Body {};

 public:
  explicit GetSystemRequest() = default;
  explicit GetSystemRequest(PathParams path_params, QueryParams query_params,
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

struct GetSystemResponse {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(GetSystemResponse, data)

 public:
  static constexpr int32_t kValidStatus = kHttpOkStatus;

 public:
  System data{};
};
