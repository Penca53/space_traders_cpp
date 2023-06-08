#include "space_traders_cpp/api/fleet/create_chart.h"

const std::string CreateChartRequest::kRelativePath = "/my/ships";

CreateChartRequest::CreateChartRequest(PathParams path_params,
                                       QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string CreateChartRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.shipSymbol + "/chart";
}
httplib::Params CreateChartRequest::HttplibParams() const {
  return httplib::Params{};
}