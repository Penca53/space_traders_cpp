#pragma once

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "space_traders_cpp/i_client.h"

class MockClient : public IClient {
 public:
  MOCK_METHOD(httplib::Result, Get,
              (const std::string& path, const httplib::Params& params,
               const httplib::Headers& headers),
              (override));
  MOCK_METHOD(httplib::Result, Post,
              (const std::string& path, const httplib::Headers& headers),
              (override));
  MOCK_METHOD(httplib::Result, Post,
              (const std::string& path, const std::string& body,
               const std::string& content_type),
              (override));
  MOCK_METHOD(httplib::Result, Post,
              (const std::string& path, const httplib::Headers& headers,
               const std::string& body, const std::string& content_type),
              (override));
  MOCK_METHOD(httplib::Result, Patch,
              (const std::string& path, const httplib::Headers& headers,
               const std::string& body, const std::string& content_type),
              (override));
};