#include "space_traders_cpp/api/contracts/deliver_contract.h"

const std::string DeliverContractRequest::kRelativePath = "/my/contracts";

DeliverContractRequest::DeliverContractRequest(PathParams path_params,
                                               QueryParams query_params,
                                               Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string DeliverContractRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.contractId + "/deliver";
}
httplib::Params DeliverContractRequest::HttplibParams() const {
  return httplib::Params{};
}