#include "space_traders_cpp/api/systems/get_waypoint.h"

const std::string GetWaypointRequest::kRelativePath = "/systems";

GetWaypointRequest::GetWaypointRequest(PathParams path_params,
                                       QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string GetWaypointRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.systemSymbol + "/waypoints/" +
         path_params.waypointSymbol;
}
httplib::Params GetWaypointRequest::HttplibParams() const {
  return httplib::Params{};
}