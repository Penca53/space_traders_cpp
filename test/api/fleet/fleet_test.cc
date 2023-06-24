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

TEST(ListShipsTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);

  const ListShipsResponse expected_list_ships =
      MakeResponse<ListShipsResponse>();
  httplib::Result expected_result = MakeResultOk(expected_list_ships);
  EXPECT_CALL(*mock_client, Get("/v2/my/ships", _, kAuthHeaders))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<ListShipsResponse, RequestError> result =
      session.ListShips(ListShipsRequest{});
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_list_ships);
}

TEST(ListShipsTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);

  const ListShipsResponse expected_list_ships =
      MakeResponse<ListShipsResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client, Get("/v2/my/ships", _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<ListShipsResponse, RequestError> result =
      session.ListShips(ListShipsRequest{});
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(PurchaseShipTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);

  const PurchaseShipResponse expected_purchase_ship =
      MakeResponse<PurchaseShipResponse>();
  httplib::Result expected_result = MakeResultOk(expected_purchase_ship);
  EXPECT_CALL(*mock_client, Post("/v2/my/ships", kAuthHeaders, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<PurchaseShipResponse, RequestError> result =
      session.PurchaseShip(PurchaseShipRequest{});
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_purchase_ship);
}

TEST(PurchaseShipTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);

  const PurchaseShipResponse expected_purchase_ship =
      MakeResponse<PurchaseShipResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client, Post("/v2/my/ships", _, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<PurchaseShipResponse, RequestError> result =
      session.PurchaseShip(PurchaseShipRequest{});
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(GetShipTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_ship = "my-ship";

  GetShipResponse expected_get_ship = MakeResponse<GetShipResponse>();
  expected_get_ship.data.symbol = my_ship;
  httplib::Result expected_result = MakeResultOk(expected_get_ship);
  EXPECT_CALL(*mock_client, Get("/v2/my/ships/" + my_ship, _, kAuthHeaders))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<GetShipResponse, RequestError> result =
      session.GetShip(GetShipRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_get_ship);
}

TEST(GetShipTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_ship = "my-ship";

  const GetShipResponse expected_get_ship = MakeResponse<GetShipResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client, Get("/v2/my/ships/" + my_ship, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<GetShipResponse, RequestError> result =
      session.GetShip(GetShipRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(GetShipCargoTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_ship = "my-ship";

  const GetShipCargoResponse expected_get_ship_cargo =
      MakeResponse<GetShipCargoResponse>();
  httplib::Result expected_result = MakeResultOk(expected_get_ship_cargo);
  EXPECT_CALL(*mock_client,
              Get("/v2/my/ships/" + my_ship + "/cargo", _, kAuthHeaders))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<GetShipCargoResponse, RequestError> result =
      session.GetShipCargo(
          GetShipCargoRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_get_ship_cargo);
}

TEST(GetShipCargoTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_ship = "my-ship";

  const GetShipCargoResponse expected_get_ship_cargo =
      MakeResponse<GetShipCargoResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client, Get("/v2/my/ships/" + my_ship + "/cargo", _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<GetShipCargoResponse, RequestError> result =
      session.GetShipCargo(
          GetShipCargoRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(OrbitShipTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_ship = "my-ship";

  const OrbitShipResponse expected_orbit_ship =
      MakeResponse<OrbitShipResponse>();
  httplib::Result expected_result = MakeResultOk(expected_orbit_ship);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/orbit", kAuthHeaders))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<OrbitShipResponse, RequestError> result =
      session.OrbitShip(OrbitShipRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_orbit_ship);
}

TEST(OrbitShipTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_ship = "my-ship";

  const OrbitShipResponse expected_orbit_ship =
      MakeResponse<OrbitShipResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client, Post("/v2/my/ships/" + my_ship + "/orbit", _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<OrbitShipResponse, RequestError> result =
      session.OrbitShip(OrbitShipRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(ShipRefineTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_ship = "my-ship";

  const ShipRefineResponse expected_ship_refine =
      MakeResponse<ShipRefineResponse>();
  httplib::Result expected_result = MakeResultOk(expected_ship_refine);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/refine", kAuthHeaders, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<ShipRefineResponse, RequestError> result =
      session.ShipRefine(ShipRefineRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_ship_refine);
}

TEST(ShipRefineTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_ship = "my-ship";

  const ShipRefineResponse expected_ship_refine =
      MakeResponse<ShipRefineResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/refine", _, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<ShipRefineResponse, RequestError> result =
      session.ShipRefine(ShipRefineRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(CreateChartTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_ship = "my-ship";

  const CreateChartResponse expected_create_chart =
      MakeResponse<CreateChartResponse>();
  httplib::Result expected_result = MakeResultOk(expected_create_chart);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/chart", kAuthHeaders))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<CreateChartResponse, RequestError> result =
      session.CreateChart(CreateChartRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_create_chart);
}

TEST(CreateChartTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_ship = "my-ship";

  const CreateChartResponse expected_create_chart =
      MakeResponse<CreateChartResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client, Post("/v2/my/ships/" + my_ship + "/chart", _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<CreateChartResponse, RequestError> result =
      session.CreateChart(CreateChartRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(GetShipCooldownTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_ship = "my-ship";

  const GetShipCooldownResponse expected_get_ship_cooldown =
      MakeResponse<GetShipCooldownResponse>();
  httplib::Result expected_result = MakeResultOk(expected_get_ship_cooldown);
  EXPECT_CALL(*mock_client,
              Get("/v2/my/ships/" + my_ship + "/cooldown", _, kAuthHeaders))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<GetShipCooldownResponse, RequestError> result =
      session.GetShipCooldown(
          GetShipCooldownRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_get_ship_cooldown);
}

TEST(GetShipCooldownTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_ship = "my-ship";

  const GetShipCooldownResponse expected_get_ship_cooldown =
      MakeResponse<GetShipCooldownResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client, Get("/v2/my/ships/" + my_ship + "/cooldown", _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<GetShipCooldownResponse, RequestError> result =
      session.GetShipCooldown(
          GetShipCooldownRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(DockShipTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_ship = "my-ship";

  const DockShipResponse expected_dock_ship = MakeResponse<DockShipResponse>();
  httplib::Result expected_result = MakeResultOk(expected_dock_ship);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/dock", kAuthHeaders))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<DockShipResponse, RequestError> result =
      session.DockShip(DockShipRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_dock_ship);
}

TEST(DockShipTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_ship = "my-ship";

  const DockShipResponse expected_dock_ship = MakeResponse<DockShipResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client, Post("/v2/my/ships/" + my_ship + "/dock", _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<DockShipResponse, RequestError> result =
      session.DockShip(DockShipRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(CreateSurveyTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_ship = "my-ship";

  const CreateSurveyResponse expected_create_survey =
      MakeResponse<CreateSurveyResponse>();
  httplib::Result expected_result = MakeResultOk(expected_create_survey);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/survey", kAuthHeaders))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<CreateSurveyResponse, RequestError> result =
      session.CreateSurvey(
          CreateSurveyRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_create_survey);
}

TEST(CreateSurveyTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_ship = "my-ship";

  const CreateSurveyResponse expected_create_survey =
      MakeResponse<CreateSurveyResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client, Post("/v2/my/ships/" + my_ship + "/survey", _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<CreateSurveyResponse, RequestError> result =
      session.CreateSurvey(
          CreateSurveyRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(ExtractResourcesTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_ship = "my-ship";

  const ExtractResourcesResponse expected_extract_resources =
      MakeResponse<ExtractResourcesResponse>();
  httplib::Result expected_result = MakeResultOk(expected_extract_resources);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/extract", kAuthHeaders, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<ExtractResourcesResponse, RequestError> result =
      session.ExtractResources(
          ExtractResourcesRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_extract_resources);
}

TEST(ExtractResourcesTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_ship = "my-ship";

  const ExtractResourcesResponse expected_extract_resources =
      MakeResponse<ExtractResourcesResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/extract", _, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<ExtractResourcesResponse, RequestError> result =
      session.ExtractResources(
          ExtractResourcesRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(JettisonCargoTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_ship = "my-ship";

  const JettisonCargoResponse expected_jettison_cargo =
      MakeResponse<JettisonCargoResponse>();
  httplib::Result expected_result = MakeResultOk(expected_jettison_cargo);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/jettison", kAuthHeaders, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<JettisonCargoResponse, RequestError> result =
      session.JettisonCargo(
          JettisonCargoRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_jettison_cargo);
}

TEST(JettisonCargoTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_ship = "my-ship";

  const JettisonCargoResponse expected_jettison_cargo =
      MakeResponse<JettisonCargoResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/jettison", _, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<JettisonCargoResponse, RequestError> result =
      session.JettisonCargo(
          JettisonCargoRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(JumpShipTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_ship = "my-ship";

  const JumpShipResponse expected_jump_ship = MakeResponse<JumpShipResponse>();
  httplib::Result expected_result = MakeResultOk(expected_jump_ship);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/jump", kAuthHeaders, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<JumpShipResponse, RequestError> result =
      session.JumpShip(JumpShipRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_jump_ship);
}

TEST(JumpShipTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_ship = "my-ship";

  const JumpShipResponse expected_jump_ship = MakeResponse<JumpShipResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client, Post("/v2/my/ships/" + my_ship + "/jump", _, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<JumpShipResponse, RequestError> result =
      session.JumpShip(JumpShipRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(NavigateShipTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_ship = "my-ship";

  const NavigateShipResponse expected_navigate_ship =
      MakeResponse<NavigateShipResponse>();
  httplib::Result expected_result = MakeResultOk(expected_navigate_ship);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/navigate", kAuthHeaders, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<NavigateShipResponse, RequestError> result =
      session.NavigateShip(
          NavigateShipRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_navigate_ship);
}

TEST(NavigateShipTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_ship = "my-ship";

  const NavigateShipResponse expected_navigate_ship =
      MakeResponse<NavigateShipResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/navigate", _, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<NavigateShipResponse, RequestError> result =
      session.NavigateShip(
          NavigateShipRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(PatchShipNavTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_ship = "my-ship";

  const PatchShipNavResponse expected_patch_ship_nav =
      MakeResponse<PatchShipNavResponse>();
  httplib::Result expected_result = MakeResultOk(expected_patch_ship_nav);
  EXPECT_CALL(*mock_client,
              Patch("/v2/my/ships/" + my_ship + "/nav", kAuthHeaders, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<PatchShipNavResponse, RequestError> result =
      session.PatchShipNav(
          PatchShipNavRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_patch_ship_nav);
}

TEST(PatchShipNavTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_ship = "my-ship";

  const PatchShipNavResponse expected_jump_ship =
      MakeResponse<PatchShipNavResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client, Patch("/v2/my/ships/" + my_ship + "/nav", _, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<PatchShipNavResponse, RequestError> result =
      session.PatchShipNav(
          PatchShipNavRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(GetShipNavTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_ship = "my-ship";

  const GetShipNavResponse expected_get_ship_nav =
      MakeResponse<GetShipNavResponse>();
  httplib::Result expected_result = MakeResultOk(expected_get_ship_nav);
  EXPECT_CALL(*mock_client,
              Get("/v2/my/ships/" + my_ship + "/nav", _, kAuthHeaders))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<GetShipNavResponse, RequestError> result =
      session.GetShipNav(GetShipNavRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_get_ship_nav);
}

TEST(GetShipNavTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_ship = "my-ship";

  const GetShipNavResponse expected_get_ship_nav =
      MakeResponse<GetShipNavResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client, Get("/v2/my/ships/" + my_ship + "/nav", _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<GetShipNavResponse, RequestError> result =
      session.GetShipNav(GetShipNavRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(WarpShipTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_ship = "my-ship";

  const WarpShipResponse expected_warp_ship = MakeResponse<WarpShipResponse>();
  httplib::Result expected_result = MakeResultOk(expected_warp_ship);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/warp", kAuthHeaders, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<WarpShipResponse, RequestError> result =
      session.WarpShip(WarpShipRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_warp_ship);
}

TEST(WarpShipTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_ship = "my-ship";

  const WarpShipResponse expected_warp_ship = MakeResponse<WarpShipResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client, Post("/v2/my/ships/" + my_ship + "/warp", _, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<WarpShipResponse, RequestError> result =
      session.WarpShip(WarpShipRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(SellCargoTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_ship = "my-ship";

  const SellCargoResponse expected_sell_cargo =
      MakeResponse<SellCargoResponse>();
  httplib::Result expected_result = MakeResultOk(expected_sell_cargo);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/sell", kAuthHeaders, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<SellCargoResponse, RequestError> result =
      session.SellCargo(SellCargoRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_sell_cargo);
}

TEST(SellCargoTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_ship = "my-ship";

  const SellCargoResponse expected_sell_cargo =
      MakeResponse<SellCargoResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client, Post("/v2/my/ships/" + my_ship + "/sell", _, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<SellCargoResponse, RequestError> result =
      session.SellCargo(SellCargoRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(ScanSystemsTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_ship = "my-ship";

  const ScanSystemsResponse expected_scan_systems =
      MakeResponse<ScanSystemsResponse>();
  httplib::Result expected_result = MakeResultOk(expected_scan_systems);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/scan/systems", kAuthHeaders))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<ScanSystemsResponse, RequestError> result =
      session.ScanSystems(ScanSystemsRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_scan_systems);
}

TEST(ScanSystemsTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_ship = "my-ship";

  const ScanSystemsResponse expected_scan_systems =
      MakeResponse<ScanSystemsResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/scan/systems", _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<ScanSystemsResponse, RequestError> result =
      session.ScanSystems(ScanSystemsRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(ScanWaypointsTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_ship = "my-ship";

  const ScanWaypointsResponse expected_scan_waypoints =
      MakeResponse<ScanWaypointsResponse>();
  httplib::Result expected_result = MakeResultOk(expected_scan_waypoints);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/scan/waypoints", kAuthHeaders))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<ScanWaypointsResponse, RequestError> result =
      session.ScanWaypoints(
          ScanWaypointsRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_scan_waypoints);
}

TEST(ScanWaypointsTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_ship = "my-ship";

  const ScanWaypointsResponse expected_scan_waypoints =
      MakeResponse<ScanWaypointsResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/scan/waypoints", _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<ScanWaypointsResponse, RequestError> result =
      session.ScanWaypoints(
          ScanWaypointsRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(ScanShipsTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_ship = "my-ship";

  const ScanShipsResponse expected_scan_ships =
      MakeResponse<ScanShipsResponse>();
  httplib::Result expected_result = MakeResultOk(expected_scan_ships);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/scan/ships", kAuthHeaders))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<ScanShipsResponse, RequestError> result =
      session.ScanShips(ScanShipsRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_scan_ships);
}

TEST(ScanShipsTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_ship = "my-ship";

  const ScanShipsResponse expected_scan_ships =
      MakeResponse<ScanShipsResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client, Post("/v2/my/ships/" + my_ship + "/scan/ships", _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<ScanShipsResponse, RequestError> result =
      session.ScanShips(ScanShipsRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(RefuelShipTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_ship = "my-ship";

  const RefuelShipResponse expected_refuel_ship =
      MakeResponse<RefuelShipResponse>();
  httplib::Result expected_result = MakeResultOk(expected_refuel_ship);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/refuel", kAuthHeaders, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<RefuelShipResponse, RequestError> result =
      session.RefuelShip(RefuelShipRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_refuel_ship);
}

TEST(RefuelShipTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_ship = "my-ship";

  const RefuelShipResponse expected_refuel_ship =
      MakeResponse<RefuelShipResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/refuel", _, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<RefuelShipResponse, RequestError> result =
      session.RefuelShip(RefuelShipRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(PurchaseCargoTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_ship = "my-ship";

  const PurchaseCargoResponse expected_purchase_cargo =
      MakeResponse<PurchaseCargoResponse>();
  httplib::Result expected_result = MakeResultOk(expected_purchase_cargo);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/purchase", kAuthHeaders, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<PurchaseCargoResponse, RequestError> result =
      session.PurchaseCargo(
          PurchaseCargoRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_purchase_cargo);
}

TEST(PurchaseCargoTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_ship = "my-ship";

  const PurchaseCargoResponse expected_purchase_cargo =
      MakeResponse<PurchaseCargoResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/purchase", _, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<PurchaseCargoResponse, RequestError> result =
      session.PurchaseCargo(
          PurchaseCargoRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(TransferCargoTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_ship = "my-ship";

  const TransferCargoResponse expected_transfer_cargo =
      MakeResponse<TransferCargoResponse>();
  httplib::Result expected_result = MakeResultOk(expected_transfer_cargo);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/transfer", kAuthHeaders, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<TransferCargoResponse, RequestError> result =
      session.TransferCargo(
          TransferCargoRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_transfer_cargo);
}

TEST(TransferCargoTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_ship = "my-ship";

  const TransferCargoResponse expected_transfer_cargo =
      MakeResponse<TransferCargoResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/transfer", _, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<TransferCargoResponse, RequestError> result =
      session.TransferCargo(
          TransferCargoRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(NegotiateContractTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_ship = "my-ship";

  const NegotiateContractResponse expected_negotiate_contract =
      MakeResponse<NegotiateContractResponse>();
  httplib::Result expected_result = MakeResultOk(expected_negotiate_contract);
  EXPECT_CALL(
      *mock_client,
      Post("/v2/my/ships/" + my_ship + "/negotiate/contract", kAuthHeaders))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<NegotiateContractResponse, RequestError> result =
      session.NegotiateContract(
          NegotiateContractRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_negotiate_contract);
}

TEST(NegotiateContractTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_ship = "my-ship";

  const NegotiateContractResponse expected_negotiate_contract =
      MakeResponse<NegotiateContractResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/negotiate/contract", _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<NegotiateContractResponse, RequestError> result =
      session.NegotiateContract(
          NegotiateContractRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(GetMountsTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_ship = "my-string";

  const GetMountsResponse expected_get_mounts =
      MakeResponse<GetMountsResponse>();
  httplib::Result expected_result = MakeResultOk(expected_get_mounts);
  EXPECT_CALL(*mock_client,
              Get("/v2/my/ships/" + my_ship + "/mounts", _, kAuthHeaders))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<GetMountsResponse, RequestError> result =
      session.GetMounts(GetMountsRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_get_mounts);
}

TEST(GetMountsTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_ship = "my-string";

  const GetMountsResponse expected_get_mounts =
      MakeResponse<GetMountsResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client, Get("/v2/my/ships/" + my_ship + "/mounts", _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<GetMountsResponse, RequestError> result =
      session.GetMounts(GetMountsRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(InstallMountTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_ship = "my-ship";

  const InstallMountResponse expected_install_mount =
      MakeResponse<InstallMountResponse>();
  httplib::Result expected_result = MakeResultOk(expected_install_mount);
  EXPECT_CALL(*mock_client, Post("/v2/my/ships/" + my_ship + "/mounts/install",
                                 kAuthHeaders, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<InstallMountResponse, RequestError> result =
      session.InstallMount(
          InstallMountRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_install_mount);
}

TEST(InstallMountTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_ship = "my-ship";

  const InstallMountResponse expected_install_mount =
      MakeResponse<InstallMountResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/mounts/install", _, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<InstallMountResponse, RequestError> result =
      session.InstallMount(
          InstallMountRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(RemoveMountTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_ship = "my-ship";

  const RemoveMountResponse expected_remove_mount =
      MakeResponse<RemoveMountResponse>();
  httplib::Result expected_result = MakeResultOk(expected_remove_mount);
  EXPECT_CALL(*mock_client, Post("/v2/my/ships/" + my_ship + "/mounts/remove",
                                 kAuthHeaders, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<RemoveMountResponse, RequestError> result =
      session.RemoveMount(RemoveMountRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_remove_mount);
}

TEST(RemoveMountTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_ship = "my-ship";

  const RemoveMountResponse expected_remove_mount =
      MakeResponse<RemoveMountResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/ships/" + my_ship + "/mounts/remove", _, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<RemoveMountResponse, RequestError> result =
      session.RemoveMount(RemoveMountRequest({.shipSymbol = my_ship}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}