#include "space_traders_cpp/api/factions/get_faction.h"

const std::string GetFactionRequest::kRelativePath = "/factions";

GetFactionRequest::GetFactionRequest(PathParams path_params,
                                     QueryParams query_params, Body body)
    : path_params_(path_params), query_params_(query_params), body_(body) {}

std::string GetFactionRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.factionSymbol;
}
httplib::Params GetFactionRequest::HttplibParams() const {
  return httplib::Params{};
}