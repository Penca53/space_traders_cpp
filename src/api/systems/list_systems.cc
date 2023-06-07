#include "space_traders_cpp/api/systems/list_systems.h"

const std::string ListSystemsRequest::kRelativePath = "/systems";

ListSystemsRequest::ListSystemsRequest(PathParams path_params,
                                       QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string ListSystemsRequest::FormattedPath() const { return kRelativePath; }
httplib::Params ListSystemsRequest::HttplibParams() const {
  return httplib::Params{{"limit", std::to_string(query_params.limit)},
                         {"page", std::to_string(query_params.page)}};
}