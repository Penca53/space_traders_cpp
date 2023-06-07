#include "space_traders_cpp/api/contracts/fulfill_contract.h"

const std::string FulfillContractRequest::kRelativePath = "/my/contracts";

FulfillContractRequest::FulfillContractRequest(PathParams path_params,
                                               QueryParams query_params,
                                               Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string FulfillContractRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.contractId + "/fulfill";
}
httplib::Params FulfillContractRequest::HttplibParams() const {
  return httplib::Params{};
}