#include "space_traders_cpp/api/fleet/sell_cargo.h"

const std::string SellCargoRequest::kRelativePath = "/my/ships";

SellCargoRequest::SellCargoRequest(PathParams path_params,
                                   QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string SellCargoRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.shipSymbol + "/sell";
}
httplib::Params SellCargoRequest::HttplibParams() const {
  return httplib::Params{};
}