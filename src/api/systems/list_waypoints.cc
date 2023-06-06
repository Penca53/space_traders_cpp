#include "space_traders_cpp/api/factions/list_waypoints.h"

const std::string ListWaypointsRequest::kRelativePath = "/systems";

ListWaypointsRequest::ListWaypointsRequest(PathParams path_params,
                                           QueryParams query_params, Body body)
    : path_params_(path_params), query_params_(query_params), body_(body) {}

std::string ListWaypointsRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.systemSymbol + "/waypoints";
}
httplib::Params ListWaypointsRequest::HttplibParams() const {
  return httplib::Params{{"limit", query_params.limit},
                         {"page", query_params.page}};
}