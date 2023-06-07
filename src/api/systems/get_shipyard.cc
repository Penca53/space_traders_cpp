#include "space_traders_cpp/api/systems/get_shipyard.h"

const std::string GetShipyardRequest::kRelativePath = "/systems";

GetShipyardRequest::GetShipyardRequest(PathParams path_params,
                                       QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string GetShipyardRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.systemSymbol + "/waypoints/" +
         path_params.waypointSymbol + "/shipyard";
}
httplib::Params GetShipyardRequest::HttplibParams() const {
  return httplib::Params{};
}