#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/contract.h"
#include "space_traders_cpp/models/meta.h"
#include "space_traders_cpp/utility.h"

struct ListContractsRequest {
 public:
  struct PathParams {};
  struct QueryParams {
    uint64_t limit = 10;
    uint64_t page = 1;
  };
  struct Body {};

 public:
  explicit ListContractsRequest() = default;
  explicit ListContractsRequest(PathParams path_params,
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

struct ListContractsResponse {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ListContractsResponse, data, meta)

 public:
  bool operator==(const ListContractsResponse&) const = default;

 public:
  static constexpr int32_t kValidStatus = kHttpOkStatus;

 public:
  std::vector<Contract> data;
  Meta meta;
  int32_t http_status = 0;
};
