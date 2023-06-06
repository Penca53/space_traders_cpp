#include "space_traders_cpp/api/factions/list_systems.h"

const std::string ListSystemsRequest::kRelativePath = "/systems";

ListSystemsRequest::ListSystemsRequest(PathParams path_params,
                                       QueryParams query_params, Body body)
    : path_params_(path_params), query_params_(query_params), body_(body) {}

std::string ListSystemsRequest::FormattedPath() const { return kRelativePath; }
httplib::Params ListSystemsRequest::HttplibParams() const {
  return httplib::Params{{"limit", query_params.limit},
                         {"page", query_params.page}};
}