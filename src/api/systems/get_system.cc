#include "space_traders_cpp/api/factions/get_system.h"

const std::string GetSystemRequest::kRelativePath = "/systems";

GetSystemRequest::GetSystemRequest(PathParams path_params,
                                   QueryParams query_params, Body body)
    : path_params_(path_params), query_params_(query_params), body_(body) {}

std::string GetSystemRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.systemSymbol;
}
httplib::Params GetSystemRequest::HttplibParams() const {
  return httplib::Params{};
}