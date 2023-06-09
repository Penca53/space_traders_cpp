#include "space_traders_cpp/api/register.h"

const std::string RegisterRequest::kRelativePath = "/register";

RegisterRequest::RegisterRequest(PathParams path_params,
                                 QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string RegisterRequest::FormattedPath() const { return kRelativePath; }
httplib::Params RegisterRequest::HttplibParams() const {
  return httplib::Params{};
}