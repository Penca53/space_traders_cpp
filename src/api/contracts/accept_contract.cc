#include "space_traders_cpp/api/contracts/accept_contract.h"

const std::string AcceptContractRequest::kRelativePath = "/my/contracts";

AcceptContractRequest::AcceptContractRequest(PathParams path_params,
                                             QueryParams query_params,
                                             Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string AcceptContractRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.contractId + "/accept";
}
httplib::Params AcceptContractRequest::HttplibParams() const {
  return httplib::Params{};
}