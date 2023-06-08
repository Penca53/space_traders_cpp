#include "space_traders_cpp/api/fleet/dock_ship.h"

const std::string DockShipRequest::kRelativePath = "/my/ships";

DockShipRequest::DockShipRequest(PathParams path_params,
                                 QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string DockShipRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.shipSymbol + "/dock";
}
httplib::Params DockShipRequest::HttplibParams() const {
  return httplib::Params{};
}