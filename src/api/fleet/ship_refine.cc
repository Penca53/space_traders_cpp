#include "space_traders_cpp/api/fleet/ship_refine.h"

const std::string ShipRefineRequest::kRelativePath = "/my/ships";

ShipRefineRequest::ShipRefineRequest(PathParams path_params,
                                     QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string ShipRefineRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.shipSymbol + "/refine";
}
httplib::Params ShipRefineRequest::HttplibParams() const {
  return httplib::Params{};
}