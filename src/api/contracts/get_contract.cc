#include "space_traders_cpp/api/contracts/get_contract.h"

const std::string GetContractRequest::kRelativePath = "/my/contracts";

GetContractRequest::GetContractRequest(PathParams path_params,
                                       QueryParams query_params, Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string GetContractRequest::FormattedPath() const {
  return kRelativePath + "/" + path_params.contractId;
}
httplib::Params GetContractRequest::HttplibParams() const {
  return httplib::Params{};
}