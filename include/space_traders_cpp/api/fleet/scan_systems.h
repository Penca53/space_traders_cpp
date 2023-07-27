#pragma once

#include "httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/cooldown.h"
#include "space_traders_cpp/models/scanned_system.h"
#include "space_traders_cpp/utility.h"

struct ScanSystemsRequest {
 public:
  struct PathParams {
    std::string shipSymbol;
  };
  struct QueryParams {};
  struct Body {};

 public:
  explicit ScanSystemsRequest() = default;
  explicit ScanSystemsRequest(PathParams path_params, QueryParams query_params,
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

struct ScanSystemsResponse {
 private:
  struct Data {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Data, cooldown, systems)

   public:
    bool operator==(const Data&) const = default;

   public:
    Cooldown cooldown{};
    std::vector<ScannedSystem> systems{};
  };

 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ScanSystemsResponse, data)

 public:
  bool operator==(const ScanSystemsResponse&) const = default;

 public:
  static constexpr int32_t kValidStatus = kHttpCreatedStatus;

 public:
  Data data{};
  int32_t http_status = 0;
};
