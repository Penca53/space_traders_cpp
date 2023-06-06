#include "space_traders_cpp/api/factions/list_factions.h"

const std::string ListFactionsRequest::kRelativePath = "/factions";

ListFactionsRequest::ListFactionsRequest(PathParams path_params,
                                         QueryParams query_params, Body body)
    : path_params_(path_params), query_params_(query_params), body_(body) {}

std::string ListFactionsRequest::FormattedPath() const { return kRelativePath; }
httplib::Params ListFactionsRequest::HttplibParams() const {
  return httplib::Params{{"limit", query_params.limit},
                         {"page", query_params.page}};
}