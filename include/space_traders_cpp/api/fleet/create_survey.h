#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/cooldown.h"
#include "space_traders_cpp/models/survey.h"
#include "space_traders_cpp/utility.h"

struct CreateSurveyRequest {
 public:
  struct PathParams {
    std::string shipSymbol;
  };
  struct QueryParams {};
  struct Body {};

 public:
  explicit CreateSurveyRequest() = default;
  explicit CreateSurveyRequest(PathParams path_params, QueryParams query_params,
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

struct CreateSurveyResponse {
  struct Data {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Data, cooldown, surveys)

   public:
    Cooldown cooldown{};
    std::vector<Survey> surveys;
  };

 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(CreateSurveyResponse, data)

 public:
  static constexpr int32_t kValidStatus = kHttpCreatedStatus;

 public:
  int32_t http_status = 0;

 public:
  Data data{};
};
