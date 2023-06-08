#include "space_traders_cpp/api/fleet/extract_resources.h"

const std::string ExtractResourcesRequest::kRelativePath = "/my/ships";

ExtractResourcesRequest::ExtractResourcesRequest(PathParams path_params,
                                                 QueryParams query_params,
                                                 Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string ExtractResourcesRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.shipSymbol + "/extract";
}
httplib::Params ExtractResourcesRequest::HttplibParams() const {
  return httplib::Params{};
}