#include "space_traders_cpp/api/fleet/negotiate_contract.h"

const std::string NegotiateContractRequest::kRelativePath = "/my/ships";

NegotiateContractRequest::NegotiateContractRequest(PathParams path_params,
                                                   QueryParams query_params,
                                                   Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string NegotiateContractRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.shipSymbol + "/negotiate/contract";
}
httplib::Params NegotiateContractRequest::HttplibParams() const {
  return httplib::Params{};
}