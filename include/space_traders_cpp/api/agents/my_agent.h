#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/agent.h"
#include "space_traders_cpp/utility.h"

struct MyAgentRequest {
 public:
  struct PathParams {};
  struct QueryParams {};
  struct Body {};

 public:
  explicit MyAgentRequest() = default;
  explicit MyAgentRequest(PathParams path_params, QueryParams query_params,
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

struct MyAgentResponse {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(MyAgentResponse, data)

 public:
  static constexpr int32_t kValidStatus = kHttpOkStatus;

 public:
  int32_t http_status = 0;

 public:
  Agent data{};
};
