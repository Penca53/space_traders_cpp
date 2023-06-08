#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/ship_cargo.h"
#include "space_traders_cpp/utility.h"

struct JettisonCargoRequest {
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
    uint64_t units = 0;
  };

 public:
  explicit JettisonCargoRequest() = default;
  explicit JettisonCargoRequest(PathParams path_params,
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

struct JettisonCargoResponse {
 private:
  struct Data {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Data, cargo)

   public:
    ShipCargo cargo{};
  };

 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(JettisonCargoResponse, data)

 public:
  static constexpr int32_t kValidStatus = kHttpOkStatus;

 public:
  Data data{};
};