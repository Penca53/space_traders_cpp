#include "space_traders_cpp_test/hello_test.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/api/agents/my_agent.h"
#include "space_traders_cpp/mock_client.h"
#include "space_traders_cpp/models/agent.h"
#include "space_traders_cpp/session.h"
#include "space_traders_cpp/utility.h"

using ::testing::_;
using ::testing::AtLeast;
using ::testing::ByRef;
using ::testing::Eq;
using ::testing::Return;

const static std::string kToken = "my-token";

const static httplib::Headers kAuthHeaders =
    httplib::Headers{{"Authorization", "Bearer " + kToken}};

TEST(StatusTest, ShouldReturnOkWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);

  const StatusResponse expected_status = MakeResponse<StatusResponse>();
  httplib::Result expected_result = MakeResultOk(expected_status);
  EXPECT_CALL(*mock_client, Get(_, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<StatusResponse, RequestError> result =
      session.Status(StatusRequest{});
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_status);
}

TEST(MyAgentTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);

  const MyAgentResponse expected_my_agent = MakeResponse<MyAgentResponse>();
  httplib::Result expected_result = MakeResultOk(expected_my_agent);
  EXPECT_CALL(*mock_client, Get(_, _, Eq(kAuthHeaders)))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<MyAgentResponse, RequestError> result =
      session.MyAgent(MyAgentRequest{});
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_my_agent);
}

TEST(MyAgentTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);

  const MyAgentResponse expected_my_agent = MakeResponse<MyAgentResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client, Get(_, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<MyAgentResponse, RequestError> result =
      session.MyAgent(MyAgentRequest{});
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}
