#include "space_traders_cpp/api/fleet/get_ship_nav.h"

const std::string GetShipNavRequest::kRelativePath = "/my/ships";

GetShipNavRequest::GetShipNavRequest(PathParams path_params,
                                     QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string GetShipNavRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.shipSymbol + "/nav";
}
httplib::Params GetShipNavRequest::HttplibParams() const {
  return httplib::Params{};
}