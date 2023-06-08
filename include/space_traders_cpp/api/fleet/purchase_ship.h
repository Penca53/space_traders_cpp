#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/agent.h"
#include "space_traders_cpp/models/market_transaction.h"
#include "space_traders_cpp/models/ship.h"
#include "space_traders_cpp/models/ship_type.h"
#include "space_traders_cpp/utility.h"

struct PurchaseShipRequest {
 public:
  struct PathParams {};
  struct QueryParams {};
  struct Body {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Body, shipType, waypointSymbol)

   public:
    ShipType shipType{};
    std::string waypointSymbol;
  };

 public:
  explicit PurchaseShipRequest() = default;
  explicit PurchaseShipRequest(PathParams path_params, QueryParams query_params,
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

struct PurchaseShipResponse {
  struct Data {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Data, agent, ship, transaction)

   public:
    Agent agent{};
    Ship ship{};
    MarketTransaction transaction{};
  };

 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(PurchaseShipResponse, data)

 public:
  static constexpr int32_t kValidStatus = kHttpCreatedStatus;

 public:
  Data data{};
};
