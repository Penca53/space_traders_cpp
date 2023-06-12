#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"

template <typename T>
T MakeResponse(const int32_t default_to_status = T::kValidStatus) {
  T expected_my_agent{};
  expected_my_agent.http_status = default_to_status;
  return expected_my_agent;
}

template <typename T>
httplib::Result MakeResult(const T& expected_object) {
  const nlohmann::json j = expected_object;
  auto http_res = std::make_unique<httplib::Response>();
  http_res->body = j.dump();
  http_res->status = T::kValidStatus;
  httplib::Result result(std::move(http_res), {});
  return result;
}