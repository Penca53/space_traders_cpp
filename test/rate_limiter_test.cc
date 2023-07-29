

#include "space_traders_cpp/rate_limiter.h"

#include <iostream>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/mock_client.h"
#include "space_traders_cpp/session.h"
#include "space_traders_cpp/utility.h"
#include "space_traders_cpp_test/api_test.h"

using ::testing::AtLeast;
using ::testing::Return;

TEST(RateLimiterTest, OneRPSShouldRunIn4Seconds) {
  const auto mock_client = std::make_shared<MockClient>();

  auto rate_limiter = std::make_unique<RateLimiter>(1);
  const Session session(mock_client, kToken, std::move(rate_limiter));
  const auto begin = std::chrono::steady_clock::now();

  for (int i = 0; i < 5; ++i) {
    const StatusResponse expected_status = MakeResponse<StatusResponse>();
    httplib::Result expected_result = MakeResultOk(expected_status);
    EXPECT_CALL(*mock_client, Get("/v2/", ::testing::_, ::testing::_))
        .Times(AtLeast(1))
        .WillOnce(Return(std::move(expected_result)));
    const Result<StatusResponse, RequestError> result =
        session.Status(StatusRequest{});
  }

  const auto elapsed = std::chrono::steady_clock::now() - begin;

  ASSERT_GE(elapsed, std::chrono::milliseconds(5000 - 1000));
}

TEST(RateLimiterTest, TwoRPSShouldRunIn4Seconds) {
  const auto mock_client = std::make_shared<MockClient>();

  auto rate_limiter = std::make_unique<RateLimiter>(2);
  const Session session(mock_client, kToken, std::move(rate_limiter));
  const auto begin = std::chrono::steady_clock::now();

  for (int i = 0; i < 10; ++i) {
    const StatusResponse expected_status = MakeResponse<StatusResponse>();
    httplib::Result expected_result = MakeResultOk(expected_status);
    EXPECT_CALL(*mock_client, Get("/v2/", ::testing::_, ::testing::_))
        .Times(AtLeast(1))
        .WillOnce(Return(std::move(expected_result)));
    const Result<StatusResponse, RequestError> result =
        session.Status(StatusRequest{});
  }

  const auto elapsed = std::chrono::steady_clock::now() - begin;

  ASSERT_GE(elapsed, std::chrono::milliseconds(5000 - 1000));
}

TEST(RateLimiterTest, ShouldRunInLessThan100Milliseconds) {
  const auto mock_client = std::make_shared<MockClient>();

  const Session session(mock_client, kToken);
  const auto begin = std::chrono::steady_clock::now();

  for (int i = 0; i < 5; ++i) {
    const StatusResponse expected_status = MakeResponse<StatusResponse>();
    httplib::Result expected_result = MakeResultOk(expected_status);
    EXPECT_CALL(*mock_client, Get("/v2/", ::testing::_, ::testing::_))
        .Times(AtLeast(1))
        .WillOnce(Return(std::move(expected_result)));
    const Result<StatusResponse, RequestError> result =
        session.Status(StatusRequest{});
  }

  const auto elapsed = std::chrono::steady_clock::now() - begin;

  ASSERT_LT(elapsed, std::chrono::milliseconds(100));
}