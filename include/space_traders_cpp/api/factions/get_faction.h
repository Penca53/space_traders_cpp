#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/faction.h"
#include "space_traders_cpp/utility.h"

struct GetFactionRequest {
 public:
  struct PathParams {
    std::string factionSymbol;
  };
  struct QueryParams {};
  struct Body {};

 public:
  explicit GetFactionRequest() = default;
  explicit GetFactionRequest(PathParams path_params, QueryParams query_params,
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

struct GetFactionResponse {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(GetFactionResponse, data)

 public:
  static constexpr int32_t kValidStatus = kGetOkStatus;

 public:
  Faction data{};
};
