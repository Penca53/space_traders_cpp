#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/agent.h"
#include "space_traders_cpp/models/market_transaction.h"
#include "space_traders_cpp/models/ship_cargo.h"
#include "space_traders_cpp/utility.h"

struct PurchaseCargoRequest {
 public:
  struct PathParams {
    std::string shipSymbol;
  };
  struct QueryParams {};
  struct Body {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Body, symbol, units)

   public:
    std::string symbol;
    int64_t units = 0;
  };

 public:
  explicit PurchaseCargoRequest() = default;
  explicit PurchaseCargoRequest(PathParams path_params,
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

struct PurchaseCargoResponse {
 private:
  struct Data {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Data, agent, cargo, transaction)

   public:
    Agent agent{};
    ShipCargo cargo{};
    MarketTransaction transaction{};
  };

 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(PurchaseCargoResponse, data)

 public:
  static constexpr int32_t kValidStatus = kHttpCreatedStatus;

 public:
  int32_t http_status = 0;

 public:
  Data data{};
};
