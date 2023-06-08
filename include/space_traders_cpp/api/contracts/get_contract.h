#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/contract.h"
#include "space_traders_cpp/utility.h"

struct GetContractRequest {
 public:
  struct PathParams {
    std::string contractId;
  };
  struct QueryParams {};
  struct Body {};

 public:
  explicit GetContractRequest() = default;
  explicit GetContractRequest(PathParams path_params, QueryParams query_params,
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

struct GetContractResponse {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(GetContractResponse, data)

 public:
  static constexpr int32_t kValidStatus = kHttpOkStatus;

 public:
  int32_t http_status = 0;

 public:
  Contract data{};
};
