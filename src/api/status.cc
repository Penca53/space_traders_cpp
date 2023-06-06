#include "space_traders_cpp/api/status.h"

const std::string StatusRequest::kRelativePath = "/";

StatusRequest::StatusRequest(PathParams path_params, QueryParams query_params,
                             Body body)
    : path_params_(path_params), query_params_(query_params), body_(body) {}

std::string StatusRequest::FormattedPath() const { return kRelativePath; }
httplib::Params StatusRequest::HttplibParams() const {
  return httplib::Params{};
}