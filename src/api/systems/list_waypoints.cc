#include "space_traders_cpp/api/systems/list_waypoints.h"

const std::string ListWaypointsRequest::kRelativePath = "/systems";

ListWaypointsRequest::ListWaypointsRequest(PathParams path_params,
                                           QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string ListWaypointsRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.systemSymbol + "/waypoints";
}
httplib::Params ListWaypointsRequest::HttplibParams() const {
  return httplib::Params{{"limit", std::to_string(query_params.limit)},
                         {"page", std::to_string(query_params.page)}};
}