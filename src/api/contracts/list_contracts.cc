#include "space_traders_cpp/api/contracts/list_contracts.h"

const std::string ListContractsRequest::kRelativePath = "/my/contracts";

ListContractsRequest::ListContractsRequest(PathParams path_params,
                                           QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string ListContractsRequest::FormattedPath() const {
  return kRelativePath;
}
httplib::Params ListContractsRequest::HttplibParams() const {
  return httplib::Params{{"limit", std::to_string(query_params.limit)},
                         {"page", std::to_string(query_params.page)}};
}