#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/api/agents/my_agent.h"
#include "space_traders_cpp/api/factions/get_faction.h"
#include "space_traders_cpp/api/factions/list_factions.h"
#include "space_traders_cpp/api/fleet/create_chart.h"
#include "space_traders_cpp/api/fleet/create_survey.h"
#include "space_traders_cpp/api/fleet/dock_ship.h"
#include "space_traders_cpp/api/fleet/extract_resources.h"
#include "space_traders_cpp/api/fleet/get_mounts.h"
#include "space_traders_cpp/api/fleet/get_ship.h"
#include "space_traders_cpp/api/fleet/get_ship_cargo.h"
#include "space_traders_cpp/api/fleet/get_ship_cooldown.h"
#include "space_traders_cpp/api/fleet/get_ship_nav.h"
#include "space_traders_cpp/api/fleet/install_mount.h"
#include "space_traders_cpp/api/fleet/jettison_cargo.h"
#include "space_traders_cpp/api/fleet/jump_ship.h"
#include "space_traders_cpp/api/fleet/list_ships.h"
#include "space_traders_cpp/api/fleet/navigate_ship.h"
#include "space_traders_cpp/api/fleet/negotiate_contract.h"
#include "space_traders_cpp/api/fleet/orbit_ship.h"
#include "space_traders_cpp/api/fleet/patch_ship_nav.h"
#include "space_traders_cpp/api/fleet/purchase_cargo.h"
#include "space_traders_cpp/api/fleet/purchase_ship.h"
#include "space_traders_cpp/api/fleet/refuel_ship.h"
#include "space_traders_cpp/api/fleet/remove_mount.h"
#include "space_traders_cpp/api/fleet/scan_ships.h"
#include "space_traders_cpp/api/fleet/scan_systems.h"
#include "space_traders_cpp/api/fleet/scan_waypoints.h"
#include "space_traders_cpp/api/fleet/sell_cargo.h"
#include "space_traders_cpp/api/fleet/ship_refine.h"
#include "space_traders_cpp/api/fleet/transfer_cargo.h"
#include "space_traders_cpp/api/fleet/warp_ship.h"
#include "space_traders_cpp/api/register.h"
#include "space_traders_cpp/api/status.h"
#include "space_traders_cpp/api/systems/get_jump_gate.h"
#include "space_traders_cpp/api/systems/get_market.h"
#include "space_traders_cpp/api/systems/get_shipyard.h"
#include "space_traders_cpp/api/systems/get_system.h"
#include "space_traders_cpp/api/systems/get_waypoint.h"
#include "space_traders_cpp/api/systems/list_systems.h"
#include "space_traders_cpp/api/systems/list_waypoints.h"
#include "space_traders_cpp/i_client.h"
#include "space_traders_cpp/utility.h"

struct LoginRequest {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(LoginRequest, token)

 public:
  std::string token;
};

struct RequestError {
 public:
  explicit RequestError(int32_t http_status, std::string body)
      : http_status(http_status), body(body) {}

 public:
  int32_t http_status = -1;
  std::string body;
};

class Session {
 public:
  explicit Session();
  explicit Session(const std::string token);
  explicit Session(const std::shared_ptr<IClient> client);
  explicit Session(const std::shared_ptr<IClient> client,
                   const std::string token);

  bool IsAPIOnline() const;
  bool IsLoggedIn() const;

  Result<MyAgentResponse, RequestError> Login(const LoginRequest& req);

  Result<StatusResponse, RequestError> Status(const StatusRequest& req) const;
  Result<RegisterResponse, RequestError> Register(
      const RegisterRequest& req) const;

  Result<ListFactionsResponse, RequestError> ListFactions(
      const ListFactionsRequest& req) const;
  Result<GetFactionResponse, RequestError> GetFaction(
      const GetFactionRequest& req) const;

  Result<ListShipsResponse, RequestError> ListShips(
      const ListShipsRequest& req) const;
  Result<PurchaseShipResponse, RequestError> PurchaseShip(
      const PurchaseShipRequest& req) const;
  Result<GetShipResponse, RequestError> GetShip(
      const GetShipRequest& req) const;
  Result<GetShipCargoResponse, RequestError> GetShipCargo(
      const GetShipCargoRequest& req) const;
  Result<OrbitShipResponse, RequestError> OrbitShip(
      const OrbitShipRequest& req) const;
  Result<ShipRefineResponse, RequestError> ShipRefine(
      const ShipRefineRequest& req) const;
  Result<CreateChartResponse, RequestError> CreateChart(
      const CreateChartRequest& req) const;
  Result<GetShipCooldownResponse, RequestError> GetShipCooldown(
      const GetShipCooldownRequest& req) const;
  Result<DockShipResponse, RequestError> DockShip(
      const DockShipRequest& req) const;
  Result<CreateSurveyResponse, RequestError> CreateSurvey(
      const CreateSurveyRequest& req) const;
  Result<ExtractResourcesResponse, RequestError> ExtractResources(
      const ExtractResourcesRequest& req) const;
  Result<JettisonCargoResponse, RequestError> JettisonCargo(
      const JettisonCargoRequest& req) const;
  Result<JumpShipResponse, RequestError> JumpShip(
      const JumpShipRequest& req) const;
  Result<NavigateShipResponse, RequestError> NavigateShip(
      const NavigateShipRequest& req) const;
  Result<PatchShipNavResponse, RequestError> PatchShipNav(
      const PatchShipNavRequest& req) const;
  Result<GetShipNavResponse, RequestError> GetShipNav(
      const GetShipNavRequest& req) const;
  Result<WarpShipResponse, RequestError> WarpShip(
      const WarpShipRequest& req) const;
  Result<SellCargoResponse, RequestError> SellCargo(
      const SellCargoRequest& req) const;
  Result<ScanSystemsResponse, RequestError> ScanSystems(
      const ScanSystemsRequest& req) const;
  Result<ScanWaypointsResponse, RequestError> ScanWaypoints(
      const ScanWaypointsRequest& req) const;
  Result<ScanShipsResponse, RequestError> ScanShips(
      const ScanShipsRequest& req) const;
  Result<RefuelShipResponse, RequestError> RefuelShip(
      const RefuelShipRequest& req) const;
  Result<PurchaseCargoResponse, RequestError> PurchaseCargo(
      const PurchaseCargoRequest& req) const;
  Result<TransferCargoResponse, RequestError> TransferCargo(
      const TransferCargoRequest& req) const;
  Result<NegotiateContractResponse, RequestError> NegotiateContract(
      const NegotiateContractRequest& req) const;
  Result<GetMountsResponse, RequestError> GetMounts(
      const GetMountsRequest& req) const;
  Result<InstallMountResponse, RequestError> InstallMounts(
      const InstallMountRequest& req) const;
  Result<RemoveMountResponse, RequestError> RemoveMounts(
      const RemoveMountRequest& req) const;

  Result<ListSystemsResponse, RequestError> ListSystems(
      const ListSystemsRequest& req) const;
  Result<GetSystemResponse, RequestError> GetSystem(
      const GetSystemRequest& req) const;
  Result<ListWaypointsResponse, RequestError> ListWaypoints(
      const ListWaypointsRequest& req) const;
  Result<GetWaypointResponse, RequestError> GetWaypoint(
      const GetWaypointRequest& req) const;
  Result<GetMarketResponse, RequestError> GetMarket(
      const GetMarketRequest& req) const;
  Result<GetShipyardResponse, RequestError> GetShipyard(
      const GetShipyardRequest& req) const;
  Result<GetJumpGateResponse, RequestError> GetJumpGate(
      const GetJumpGateRequest& req) const;
  Result<MyAgentResponse, RequestError> MyAgent(
      const MyAgentRequest& req) const;

 private:
  template <typename R>
  httplib::Result MakeGet(const R& request) const {
    return client_->Get(kBasePath + request.FormattedPath(),
                        request.HttplibParams(), httplib::Headers{});
  }
  template <typename R>
  httplib::Result MakePost(
      const R& request, std::string content_type = "application/json") const {
    const nlohmann::json j = request.body;
    return client_->Post(kBasePath + request.FormattedPath(), j.dump(),
                         content_type);
  }
  template <typename R>
  httplib::Result MakePatch(
      const R& request, std::string content_type = "application/json") const {
    const nlohmann::json j = request.body;
    return client_->Patch(kBasePath + request.FormattedPath(), j.dump(),
                          content_type);
  }
  template <typename R>
  httplib::Result MakeAuthGet(const R& request) const {
    return client_->Get(
        kBasePath + request.FormattedPath(), request.HttplibParams(),
        httplib::Headers{{"Authorization", "Bearer " + token_}});
  }
  template <typename R>
  httplib::Result MakeAuthPost(
      const R& request, std::string content_type = "application/json") const {
    constexpr bool has_to_json = requires(const R& r) { r.to_json(); };

    if constexpr (has_to_json) {
      const nlohmann::json j = request.body;
      return client_->Post(
          kBasePath + request.FormattedPath(),
          httplib::Headers{{"Authorization", "Bearer " + token_}}, j.dump(),
          content_type);
    } else {
      return client_->Post(
          kBasePath + request.FormattedPath(),
          httplib::Headers{{"Authorization", "Bearer " + token_}});
    }
  }
  template <typename R>
  httplib::Result MakeAuthPatch(
      const R& request, std::string content_type = "application/json") const {
    const nlohmann::json j = request.body;
    return client_->Patch(
        kBasePath + request.FormattedPath(),
        httplib::Headers{{"Authorization", "Bearer " + token_}}, j.dump(),
        content_type);
  }

  template <typename R>
  Result<R, RequestError> ResponseBodyOrError(
      const httplib::Result& result) const {
    if (result->status != R::kValidStatus) {
      const RequestError err(result->status, result->body);
      return Err(err);
    }

    const nlohmann::json j = j.parse(result->body);
    R response = j.get<R>();
    response.http_status = result->status;
    return Ok(response);
  }

 private:
  std::string token_;
  std::shared_ptr<IClient> client_;
  static const std::string kBasePath;
};