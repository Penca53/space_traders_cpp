#include "space_traders_cpp/api/factions/list_factions.h"

const std::string ListFactionsRequest::kRelativePath = "/factions";

ListFactionsRequest::ListFactionsRequest(PathParams path_params,
                                         QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string ListFactionsRequest::FormattedPath() const { return kRelativePath; }
httplib::Params ListFactionsRequest::HttplibParams() const {
  return httplib::Params{{"limit", std::to_string(query_params.limit)},
                         {"page", std::to_string(query_params.page)}};
}