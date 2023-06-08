#include "space_traders_cpp/api/fleet/scan_systems.h"

const std::string ScanSystemsRequest::kRelativePath = "/my/ships";

ScanSystemsRequest::ScanSystemsRequest(PathParams path_params,
                                       QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string ScanSystemsRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.shipSymbol + "/scan/systems";
}
httplib::Params ScanSystemsRequest::HttplibParams() const {
  return httplib::Params{};
}