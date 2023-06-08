#include "space_traders_cpp/api/fleet/patch_ship_nav.h"

const std::string PatchShipNavRequest::kRelativePath = "/my/ships";

PatchShipNavRequest::PatchShipNavRequest(PathParams path_params,
                                         QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string PatchShipNavRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.shipSymbol + "/nav";
}
httplib::Params PatchShipNavRequest::HttplibParams() const {
  return httplib::Params{};
}