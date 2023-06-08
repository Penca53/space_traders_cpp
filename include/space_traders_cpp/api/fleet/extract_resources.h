#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/cooldown.h"
#include "space_traders_cpp/models/extraction.h"
#include "space_traders_cpp/models/ship_cargo.h"
#include "space_traders_cpp/models/survey.h"
#include "space_traders_cpp/utility.h"

struct ExtractResourcesRequest {
 public:
  struct PathParams {
    std::string shipSymbol;
  };
  struct QueryParams {};
  struct Body {
    friend void to_json(nlohmann::json& j, const Body& b) {
      j["survey"] = b.survey;
    }
    friend void from_json(const nlohmann::json& j, Body& b) {
      if (j.contains("survey")) {
        j.at("survey").get_to(b.survey);
      }
    }

   public:
    std::optional<Survey> survey;
  };

 public:
  explicit ExtractResourcesRequest() = default;
  explicit ExtractResourcesRequest(PathParams path_params,
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

struct ExtractResourcesResponse {
 private:
  struct Data {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Data, cooldown, extraction, cargo)

   public:
    Cooldown cooldown{};
    Extraction extraction{};
    ShipCargo cargo{};
  };

 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ExtractResourcesResponse, data)

 public:
  static constexpr int32_t kValidStatus = kHttpCreatedStatus;

 public:
  int32_t http_status = 0;

 public:
  Data data{};
};
