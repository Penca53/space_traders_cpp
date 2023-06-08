#include "space_traders_cpp/api/fleet/warp_ship.h"

const std::string WarpShipRequest::kRelativePath = "/my/ships";

WarpShipRequest::WarpShipRequest(PathParams path_params,
                                 QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string WarpShipRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.shipSymbol + "/warp";
}
httplib::Params WarpShipRequest::HttplibParams() const {
  return httplib::Params{};
}