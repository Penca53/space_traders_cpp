#include "space_traders_cpp/api/register.h"

const std::string RegisterRequest::kRelativePath = "/register";

RegisterRequest::RegisterRequest(PathParams path_params,
                                 QueryParams query_params, Body body)
    : path_params_(path_params), query_params_(query_params), body_(body) {}

std::string RegisterRequest::FormattedPath() const { return kRelativePath; }
