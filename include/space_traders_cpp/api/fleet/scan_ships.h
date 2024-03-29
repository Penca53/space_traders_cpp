#pragma once

#include "httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/cooldown.h"
#include "space_traders_cpp/models/scanned_ship.h"
#include "space_traders_cpp/utility.h"

struct ScanShipsRequest {
 public:
  struct PathParams {
    std::string shipSymbol;
  };
  struct QueryParams {};
  struct Body {};

 public:
  explicit ScanShipsRequest() = default;
  explicit ScanShipsRequest(PathParams path_params, QueryParams query_params,
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

struct ScanShipsResponse {
 private:
  struct Data {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Data, cooldown, ships)

   public:
    bool operator==(const Data&) const = default;

   public:
    Cooldown cooldown{};
    std::vector<ScannedShip> ships{};
  };

 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ScanShipsResponse, data)

 public:
  bool operator==(const ScanShipsResponse&) const = default;

 public:
  static constexpr int32_t kValidStatus = kHttpCreatedStatus;

 public:
  Data data{};
  int32_t http_status = 0;
};
