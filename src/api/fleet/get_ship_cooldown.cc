#include "space_traders_cpp/api/fleet/get_ship_cooldown.h"

const std::string GetShipCooldownRequest::kRelativePath = "/my/ships";

GetShipCooldownRequest::GetShipCooldownRequest(PathParams path_params,
                                               QueryParams query_params,
                                               Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string GetShipCooldownRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.shipSymbol + "/cooldown";
}
httplib::Params GetShipCooldownRequest::HttplibParams() const {
  return httplib::Params{};
}