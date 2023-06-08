#include "space_traders_cpp/api/fleet/transfer_cargo.h"

const std::string TransferCargoRequest::kRelativePath = "/my/ships";

TransferCargoRequest::TransferCargoRequest(PathParams path_params,
                                           QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string TransferCargoRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.shipSymbol + "/transfer";
}
httplib::Params TransferCargoRequest::HttplibParams() const {
  return httplib::Params{};
}