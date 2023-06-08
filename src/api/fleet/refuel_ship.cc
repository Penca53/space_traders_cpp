#include "space_traders_cpp/api/fleet/refuel_ship.h"

const std::string RefuelShipRequest::kRelativePath = "/my/ships";

RefuelShipRequest::RefuelShipRequest(PathParams path_params,
                                     QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string RefuelShipRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.shipSymbol + "/refuel";
}
httplib::Params RefuelShipRequest::HttplibParams() const {
  return httplib::Params{};
}