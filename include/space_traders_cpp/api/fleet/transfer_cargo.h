#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/ship_cargo.h"
#include "space_traders_cpp/models/trade_symbol.h"
#include "space_traders_cpp/utility.h"

struct TransferCargoRequest {
 public:
  struct PathParams {
    std::string shipSymbol;
  };
  struct QueryParams {};
  struct Body {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Body, tradeSymbol, symbol, units)

   public:
    TradeSymbol tradeSymbol{};
    std::string symbol;
    int64_t units = 0;
  };

 public:
  explicit TransferCargoRequest() = default;
  explicit TransferCargoRequest(PathParams path_params,
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

struct TransferCargoResponse {
 private:
  struct Data {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Data, cargo)

   public:
    ShipCargo cargo{};
  };

 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(TransferCargoResponse, data)

 public:
  static constexpr int32_t kValidStatus = kHttpOkStatus;

 public:
  Data data{};
};