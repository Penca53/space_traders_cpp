#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/agent.h"
#include "space_traders_cpp/models/market_transaction.h"
#include "space_traders_cpp/models/ship_cargo.h"
#include "space_traders_cpp/models/ship_mount.h"
#include "space_traders_cpp/utility.h"

struct InstallMountRequest {
 public:
  struct PathParams {
    std::string shipSymbol;
  };
  struct QueryParams {};
  struct Body {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Body, symbol)

   public:
    std::string symbol;
  };

 public:
  explicit InstallMountRequest() = default;
  explicit InstallMountRequest(PathParams path_params, QueryParams query_params,
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

struct InstallMountResponse {
 private:
  struct Data {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Data, cargo)

   public:
    Agent agent{};
    std::vector<ShipMount> mounts;
    ShipCargo cargo{};
    MarketTransaction transaction{};
  };

 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(InstallMountResponse, data)

 public:
  static constexpr int32_t kValidStatus = kHttpCreatedStatus;

 public:
  Data data{};
};
