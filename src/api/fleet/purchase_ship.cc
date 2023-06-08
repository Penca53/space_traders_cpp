#include "space_traders_cpp/api/fleet/purchase_ship.h"

const std::string PurchaseShipRequest::kRelativePath = "/my/ships";

PurchaseShipRequest::PurchaseShipRequest(PathParams path_params,
                                         QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string PurchaseShipRequest::FormattedPath() const { return kRelativePath; }
httplib::Params PurchaseShipRequest::HttplibParams() const {
  return httplib::Params{};
}