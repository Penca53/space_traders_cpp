#include "space_traders_cpp/api/systems/get_market.h"

const std::string GetMarketRequest::kRelativePath = "/systems";

GetMarketRequest::GetMarketRequest(PathParams path_params,
                                   QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string GetMarketRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.systemSymbol + "/waypoints" +
         path_params.waypointSymbol + "/market";
}
httplib::Params GetMarketRequest::HttplibParams() const {
  return httplib::Params{};
}