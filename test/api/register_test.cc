#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/mock_client.h"
#include "space_traders_cpp/session.h"
#include "space_traders_cpp/utility.h"
#include "space_traders_cpp_test/api_test.h"

using ::testing::AtLeast;
using ::testing::ByRef;
using ::testing::Eq;
using ::testing::Return;

TEST(RegisterTest, ShouldReturnOkWhenSymbolNotInUse) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_symbol = "my-symbol";
  const std::string faction_symbol = "COSMIC";

  RegisterResponse expected_register = MakeResponse<RegisterResponse>();
  expected_register.data.faction.symbol = faction_symbol;
  expected_register.data.agent.symbol = my_symbol;
  httplib::Result expected_result = MakeResultOk(expected_register);
  EXPECT_CALL(*mock_client, Post("/v2/register", ::testing::_, ::testing::_))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<RegisterResponse, RequestError> result =
      session.Register(RegisterRequest{});
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_register);
}

TEST(RegisterTest, ShouldReturnErrWhenSymbolAlreadyInUse) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_symbol = "my-symbol";
  const std::string faction_symbol = "COSMIC";

  RegisterResponse expected_register = MakeResponse<RegisterResponse>();
  expected_register.data.faction.symbol = faction_symbol;
  expected_register.data.agent.symbol = my_symbol;
  httplib::Result expected_result =
      MakeResultErr(kHttpUnprocessableEntityStatus);
  EXPECT_CALL(*mock_client, Post("/v2/register", ::testing::_, ::testing::_))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<RegisterResponse, RequestError> result =
      session.Register(RegisterRequest{});
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnprocessableEntityStatus);
}