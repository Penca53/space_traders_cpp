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

TEST(ListSystemsTest, ShouldReturnOkWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);

  const ListSystemsResponse expected_list_systems =
      MakeResponse<ListSystemsResponse>();
  httplib::Result expected_result = MakeResultOk(expected_list_systems);
  EXPECT_CALL(*mock_client, Get("/v2/systems", _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<ListSystemsResponse, RequestError> result =
      session.ListSystems(ListSystemsRequest{});
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_list_systems);
}

TEST(GetSystemTest, ShouldReturnOkWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_system = "my-system";

  GetSystemResponse expected_get_system = MakeResponse<GetSystemResponse>();
  expected_get_system.data.symbol = my_system;
  httplib::Result expected_result = MakeResultOk(expected_get_system);
  EXPECT_CALL(*mock_client, Get("/v2/systems/" + my_system, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<GetSystemResponse, RequestError> result =
      session.GetSystem(GetSystemRequest({.systemSymbol = my_system}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_get_system);
}

TEST(ListWaypointsTest, ShouldReturnOkWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_system = "my-system";

  const ListWaypointsResponse expected_list_waypoints =
      MakeResponse<ListWaypointsResponse>();
  httplib::Result expected_result = MakeResultOk(expected_list_waypoints);
  EXPECT_CALL(*mock_client,
              Get("/v2/systems/" + my_system + "/waypoints", _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<ListWaypointsResponse, RequestError> result =
      session.ListWaypoints(
          ListWaypointsRequest({.systemSymbol = my_system}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_list_waypoints);
}

TEST(GetWaypointTest, ShouldReturnOkWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_system = "my-system";
  const std::string my_waypoint = "my-waypoint";

  const GetWaypointResponse expected_get_waypoint =
      MakeResponse<GetWaypointResponse>();
  httplib::Result expected_result = MakeResultOk(expected_get_waypoint);
  EXPECT_CALL(
      *mock_client,
      Get("/v2/systems/" + my_system + "/waypoints/" + my_waypoint, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<GetWaypointResponse, RequestError> result =
      session.GetWaypoint(GetWaypointRequest(
          {.systemSymbol = my_system, .waypointSymbol = my_waypoint}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_get_waypoint);
}

TEST(GetMarketTest, ShouldReturnOkWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_system = "my-system";
  const std::string my_waypoint = "my-waypoint";

  const GetMarketResponse expected_get_market =
      MakeResponse<GetMarketResponse>();
  httplib::Result expected_result = MakeResultOk(expected_get_market);
  EXPECT_CALL(*mock_client, Get("/v2/systems/" + my_system + "/waypoints/" +
                                    my_waypoint + "/market",
                                _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<GetMarketResponse, RequestError> result =
      session.GetMarket(GetMarketRequest(
          {.systemSymbol = my_system, .waypointSymbol = my_waypoint}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_get_market);
}

TEST(GetShipyardTest, ShouldReturnOkWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_system = "my-system";
  const std::string my_waypoint = "my-waypoint";

  const GetShipyardResponse expected_get_shipyard =
      MakeResponse<GetShipyardResponse>();
  httplib::Result expected_result = MakeResultOk(expected_get_shipyard);
  EXPECT_CALL(*mock_client, Get("/v2/systems/" + my_system + "/waypoints/" +
                                    my_waypoint + "/shipyard",
                                _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<GetShipyardResponse, RequestError> result =
      session.GetShipyard(GetShipyardRequest(
          {.systemSymbol = my_system, .waypointSymbol = my_waypoint}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_get_shipyard);
}

TEST(GetJumpGateTest, ShouldReturnOkWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_system = "my-system";
  const std::string my_waypoint = "my-waypoint";

  const GetJumpGateResponse expected_get_jump_gate =
      MakeResponse<GetJumpGateResponse>();
  httplib::Result expected_result = MakeResultOk(expected_get_jump_gate);
  EXPECT_CALL(*mock_client, Get("/v2/systems/" + my_system + "/waypoints/" +
                                    my_waypoint + "/jump-gate",
                                _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<GetJumpGateResponse, RequestError> result =
      session.GetJumpGate(GetJumpGateRequest(
          {.systemSymbol = my_system, .waypointSymbol = my_waypoint}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_get_jump_gate);
}