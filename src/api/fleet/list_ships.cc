#include "space_traders_cpp/api/fleet/list_ships.h"

const std::string ListShipsRequest::kRelativePath = "/my/ships";

ListShipsRequest::ListShipsRequest(PathParams path_params,
                                   QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string ListShipsRequest::FormattedPath() const { return kRelativePath; }
httplib::Params ListShipsRequest::HttplibParams() const {
  return httplib::Params{{"limit", std::to_string(query_params.limit)},
                         {"page", std::to_string(query_params.page)}};
}