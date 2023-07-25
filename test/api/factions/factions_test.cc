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

TEST(ListFactionsTest, ShouldReturnOkWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);

  const ListFactionsResponse expected_list_factions =
      MakeResponse<ListFactionsResponse>();
  httplib::Result expected_result = MakeResultOk(expected_list_factions);
  EXPECT_CALL(*mock_client, Get("/v2/factions", ::testing::_, ::testing::_))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<ListFactionsResponse, RequestError> result =
      session.ListFactions(ListFactionsRequest{});
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_list_factions);
}

TEST(GetFactionTest, ShouldReturnOkWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_faction = "my-faction";

  GetFactionResponse expected_get_faction = MakeResponse<GetFactionResponse>();
  expected_get_faction.data.symbol = my_faction;
  httplib::Result expected_result = MakeResultOk(expected_get_faction);
  EXPECT_CALL(*mock_client,
              Get("/v2/factions/" + my_faction, ::testing::_, ::testing::_))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<GetFactionResponse, RequestError> result = session.GetFaction(
      GetFactionRequest({.factionSymbol = my_faction}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_get_faction);
}