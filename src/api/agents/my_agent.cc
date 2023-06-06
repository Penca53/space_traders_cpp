#include "space_traders_cpp/api/agents/my_agent.h"

const std::string MyAgentRequest::kRelativePath = "/my/agent";

MyAgentRequest::StatusRequest(PathParams path_params, QueryParams query_params,
                              Body body)
    : path_params_(path_params), query_params_(query_params), body_(body) {}

std::string MyAgentRequest::FormattedPath() const { return kRelativePath; }
httplib::Params MyAgentRequest::HttplibParams() const {
  return httplib::Params{};
}
