#pragma once

#include "httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/agent.h"
#include "space_traders_cpp/models/contract.h"
#include "space_traders_cpp/utility.h"

struct FulfillContractRequest {
 public:
  struct PathParams {
    std::string contractId;
  };
  struct QueryParams {};
  struct Body {};

 public:
  explicit FulfillContractRequest() = default;
  explicit FulfillContractRequest(PathParams path_params,
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

struct FulfillContractResponse {
 private:
  struct Data {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Data, agent, contract)

   public:
    bool operator==(const Data&) const = default;

   public:
    Agent agent{};
    Contract contract{};
  };

 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(FulfillContractResponse, data)

 public:
  bool operator==(const FulfillContractResponse&) const = default;

 public:
  static constexpr int32_t kValidStatus = kHttpOkStatus;

 public:
  Data data{};
  int32_t http_status = 0;
};
