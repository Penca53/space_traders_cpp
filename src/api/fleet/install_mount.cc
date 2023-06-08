#include "space_traders_cpp/api/fleet/install_mount.h"

const std::string InstallMountRequest::kRelativePath = "/my/ships";

InstallMountRequest::InstallMountRequest(PathParams path_params,
                                         QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string InstallMountRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.shipSymbol + "/mounts/install";
}
httplib::Params InstallMountRequest::HttplibParams() const {
  return httplib::Params{};
}