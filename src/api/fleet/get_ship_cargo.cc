#include "space_traders_cpp/api/fleet/get_ship_cargo.h"

const std::string GetShipCargoRequest::kRelativePath = "/my/ships";

GetShipCargoRequest::GetShipCargoRequest(PathParams path_params,
                                         QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string GetShipCargoRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.shipSymbol + "/cargo";
}
httplib::Params GetShipCargoRequest::HttplibParams() const {
  return httplib::Params{};
}