#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/contract.h"
#include "space_traders_cpp/models/ship_cargo.h"
#include "space_traders_cpp/utility.h"

struct DeliverContractRequest {
 public:
  struct PathParams {
    std::string contractId;
  };
  struct QueryParams {};
  struct Body {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Body, shipSymbol, tradeSymbol, units)

   public:
    std::string shipSymbol;
    std::string tradeSymbol;
    int64_t units = 0;
  };

 public:
  explicit DeliverContractRequest() = default;
  explicit DeliverContractRequest(PathParams path_params,
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

struct DeliverContractResponse {
 private:
  struct Data {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Data, contract, cargo)

   public:
    Contract contract{};
    ShipCargo cargo{};
  };

 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(DeliverContractResponse, data)

 public:
  static constexpr int32_t kValidStatus = kHttpOkStatus;

 public:
  int32_t http_status = 0;

 public:
  Data data{};
};
