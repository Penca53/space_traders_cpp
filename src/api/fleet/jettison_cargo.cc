#include "space_traders_cpp/api/fleet/jettison_cargo.h"

const std::string JettisonCargoRequest::kRelativePath = "/my/ships";

JettisonCargoRequest::JettisonCargoRequest(PathParams path_params,
                                           QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string JettisonCargoRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.shipSymbol + "/jettison";
}
httplib::Params JettisonCargoRequest::HttplibParams() const {
  return httplib::Params{};
}