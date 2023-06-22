#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/mock_client.h"
#include "space_traders_cpp/session.h"
#include "space_traders_cpp/utility.h"
#include "space_traders_cpp_test/api_test.h"

using ::testing::_;
using ::testing::AtLeast;
using ::testing::ByRef;
using ::testing::Eq;
using ::testing::Return;

TEST(StatusTest, ShouldReturnOkWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);

  const StatusResponse expected_status = MakeResponse<StatusResponse>();
  httplib::Result expected_result = MakeResultOk(expected_status);
  EXPECT_CALL(*mock_client, Get("/v2/", _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<StatusResponse, RequestError> result =
      session.Status(StatusRequest{});
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_status);
}