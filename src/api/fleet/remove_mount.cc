#include "space_traders_cpp/api/fleet/remove_mount.h"

const std::string RemoveMountRequest::kRelativePath = "/my/ships";

RemoveMountRequest::RemoveMountRequest(PathParams path_params,
                                       QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string RemoveMountRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.shipSymbol + "/mounts/remove";
}
httplib::Params RemoveMountRequest::HttplibParams() const {
  return httplib::Params{};
}