#include "space_traders_cpp/api/fleet/get_ship.h"

const std::string GetShipRequest::kRelativePath = "/my/ships";

GetShipRequest::GetShipRequest(PathParams path_params, QueryParams query_params,
                               Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string GetShipRequest::FormattedPath() const { return kRelativePath; }
httplib::Params GetShipRequest::HttplibParams() const {
  return httplib::Params{};
}