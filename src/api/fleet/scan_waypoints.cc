#include "space_traders_cpp/api/fleet/scan_waypoints.h"

const std::string ScanWaypointsRequest::kRelativePath = "/my/ships";

ScanWaypointsRequest::ScanWaypointsRequest(PathParams path_params,
                                           QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string ScanWaypointsRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.shipSymbol + "/scan/waypoints";
}
httplib::Params ScanWaypointsRequest::HttplibParams() const {
  return httplib::Params{};
}