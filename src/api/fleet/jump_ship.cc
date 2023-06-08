#include "space_traders_cpp/api/fleet/jump_ship.h"

const std::string JumpShipRequest::kRelativePath = "/my/ships";

JumpShipRequest::JumpShipRequest(PathParams path_params,
                                 QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string JumpShipRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.shipSymbol + "/jump";
}
httplib::Params JumpShipRequest::HttplibParams() const {
  return httplib::Params{};
}