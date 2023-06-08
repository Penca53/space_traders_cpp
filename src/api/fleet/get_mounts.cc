#include "space_traders_cpp/api/fleet/get_mounts.h"

const std::string GetMountsRequest::kRelativePath = "/my/ships";

GetMountsRequest::GetMountsRequest(PathParams path_params,
                                   QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string GetMountsRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.shipSymbol + "/mounts";
}
httplib::Params GetMountsRequest::HttplibParams() const {
  return httplib::Params{};
}