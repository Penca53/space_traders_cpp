#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/agent.h"
#include "space_traders_cpp/models/contract.h"
#include "space_traders_cpp/utility.h"

struct AcceptContractRequest {
 public:
  struct PathParams {
    std::string contractId;
  };
  struct QueryParams {};
  struct Body {};

 public:
  explicit AcceptContractRequest() = default;
  explicit AcceptContractRequest(PathParams path_params,
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

struct AcceptContractResponse {
 private:
  struct Data {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Data, agent, contract)

   public:
    Agent agent{};
    Contract contract{};
  };

 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(AcceptContractResponse, data)

 public:
  static constexpr int32_t kValidStatus = kGetOkStatus;

 public:
  Data data{};
};
