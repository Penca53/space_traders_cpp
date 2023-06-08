#include "space_traders_cpp/api/fleet/navigate_ship.h"

const std::string NavigateShipRequest::kRelativePath = "/my/ships";

NavigateShipRequest::NavigateShipRequest(PathParams path_params,
                                         QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string NavigateShipRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.shipSymbol + "/navigate";
}
httplib::Params NavigateShipRequest::HttplibParams() const {
  return httplib::Params{};
}