#include "space_traders_cpp/api/fleet/orbit_ship.h"

const std::string OrbitShipRequest::kRelativePath = "/my/ships";

OrbitShipRequest::OrbitShipRequest(PathParams path_params,
                                   QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string OrbitShipRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.shipSymbol + "/orbit";
}
httplib::Params OrbitShipRequest::HttplibParams() const {
  return httplib::Params{};
}