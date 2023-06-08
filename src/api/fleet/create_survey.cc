#include "space_traders_cpp/api/fleet/create_survey.h"

const std::string CreateSurveyRequest::kRelativePath = "/my/ships";

CreateSurveyRequest::CreateSurveyRequest(PathParams path_params,
                                         QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string CreateSurveyRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.shipSymbol + "/survey";
}
httplib::Params CreateSurveyRequest::HttplibParams() const {
  return httplib::Params{};
}