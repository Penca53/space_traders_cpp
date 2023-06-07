#include "space_traders_cpp/api/systems/get_jump_gate.h"

const std::string GetJumpGateRequest::kRelativePath = "/systems";

GetJumpGateRequest::GetJumpGateRequest(PathParams path_params,
                                       QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string GetJumpGateRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.systemSymbol + "/waypoints" +
         path_params.waypointSymbol + "/jump-gate";
}
httplib::Params GetJumpGateRequest::HttplibParams() const {
  return httplib::Params{};
}