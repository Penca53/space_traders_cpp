#include "space_traders_cpp/api/agents/my_agent.h"

const std::string MyAgentRequest::kRelativePath = "/my/agent";

MyAgentRequest::MyAgentRequest(PathParams path_params, QueryParams query_params,
                               Body body)
    : path_params(path_params), query_params(query_params), body(body) {}

std::string MyAgentRequest::FormattedPath() const { return kRelativePath; }
httplib::Params MyAgentRequest::HttplibParams() const {
  return httplib::Params{};
}
