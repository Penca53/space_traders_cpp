#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/agent.h"
#include "space_traders_cpp/models/market_transaction.h"
#include "space_traders_cpp/models/ship_fuel.h"
#include "space_traders_cpp/utility.h"

struct RefuelShipRequest {
 public:
  struct PathParams {
    std::string shipSymbol;
  };
  struct QueryParams {};
  struct Body {};

 public:
  explicit RefuelShipRequest() = default;
  explicit RefuelShipRequest(PathParams path_params, QueryParams query_params,
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

struct RefuelShipResponse {
 private:
  struct Data {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Data, agent, fuel, transaction)

   public:
    Agent agent{};
    ShipFuel fuel{};
    MarketTransaction transaction{};
  };

 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(RefuelShipResponse, data)

 public:
  static constexpr int32_t kValidStatus = kHttpOkStatus;

 public:
  Data data{};
};
