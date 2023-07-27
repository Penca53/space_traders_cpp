#pragma once

#include "httplib.h"
#include "nlohmann/json.hpp"

const static std::string kToken = "my-token";

const static httplib::Headers kAuthHeaders =
    httplib::Headers{{"Authorization", "Bearer " + kToken}};

template <typename T>
T MakeResponse(const int32_t default_to_status = T::kValidStatus) {
  T expected_my_agent{};
  expected_my_agent.http_status = default_to_status;
  return expected_my_agent;
}

template <typename T>
httplib::Result MakeResultOk(const T& expected_object) {
  const nlohmann::json j = expected_object;
  auto http_res = std::make_unique<httplib::Response>();
  http_res->body = j.dump();
  http_res->status = T::kValidStatus;
  httplib::Result result(std::move(http_res), {});
  return result;
}

inline httplib::Result MakeResultErr(const int32_t http_status) {
  auto http_res = std::make_unique<httplib::Response>();
  http_res->status = http_status;
  httplib::Result result(std::move(http_res), {});
  return result;
}