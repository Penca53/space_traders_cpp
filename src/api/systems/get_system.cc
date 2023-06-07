#include "space_traders_cpp/api/systems/get_system.h"

const std::string GetSystemRequest::kRelativePath = "/systems";

GetSystemRequest::GetSystemRequest(PathParams path_params,
                                   QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string GetSystemRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.systemSymbol;
}
httplib::Params GetSystemRequest::HttplibParams() const {
  return httplib::Params{};
}