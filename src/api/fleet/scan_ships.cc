#include "space_traders_cpp/api/fleet/scan_ships.h"

const std::string ScanShipsRequest::kRelativePath = "/my/ships";

ScanShipsRequest::ScanShipsRequest(PathParams path_params,
                                   QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string ScanShipsRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.shipSymbol + "/scan/ships";
}
httplib::Params ScanShipsRequest::HttplibParams() const {
  return httplib::Params{};
}