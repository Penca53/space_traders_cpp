#include "space_traders_cpp/api/fleet/purchase_cargo.h"

const std::string PurchaseCargoRequest::kRelativePath = "/my/ships";

PurchaseCargoRequest::PurchaseCargoRequest(PathParams path_params,
                                           QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string PurchaseCargoRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.shipSymbol + "/purchase";
}
httplib::Params PurchaseCargoRequest::HttplibParams() const {
  return httplib::Params{};
}