#pragma once

#include "httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/contract.h"
#include "space_traders_cpp/utility.h"

struct NegotiateContractRequest {
 public:
  struct PathParams {
    std::string shipSymbol;
  };
  struct QueryParams {};
  struct Body {};

 public:
  explicit NegotiateContractRequest() = default;
  explicit NegotiateContractRequest(PathParams path_params,
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

struct NegotiateContractResponse {
 private:
  struct Data {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Data, contract)

   public:
    bool operator==(const Data&) const = default;

   public:
    Contract contract{};
  };

 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(NegotiateContractResponse, data)

 public:
  bool operator==(const NegotiateContractResponse&) const = default;

 public:
  static constexpr int32_t kValidStatus = kHttpCreatedStatus;

 public:
  Data data{};
  int32_t http_status = 0;
};
