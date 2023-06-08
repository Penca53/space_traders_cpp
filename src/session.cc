#include "space_traders_cpp/session.h"

#include "space_traders_cpp/utility.h"

const std::string Session::kBasePath = "/v2";

Session::Session() : client_("https://api.spacetraders.io") {}
Session::Session(std::string token)
    : token_(token), client_("https://api.spacetraders.io") {}

bool Session::IsAPIOnline() {
  Result<StatusResponse, RequestError> status_res = Status(StatusRequest{});
  if (status_res.IsErr()) {
    return false;
  }
  return status_res.Ok().status.find("online") != std::string::npos;
}
bool Session::IsLoggedIn() { return MyAgent(MyAgentRequest{}).IsOk(); }

Result<MyAgentResponse, RequestError> Session::Login(const LoginRequest& req) {
  token_ = req.token;
  return MyAgent(MyAgentRequest{});
}
Result<StatusResponse, RequestError> Session::Status(const StatusRequest& req) {
  httplib::Result result = MakeGet(req);
  return ResponseBodyOrError<StatusResponse>(result);
}
Result<RegisterResponse, RequestError> Session::Register(
    const RegisterRequest& req) {
  httplib::Result result = MakePost(req);
  return ResponseBodyOrError<RegisterResponse>(result);
}
Result<ListFactionsResponse, RequestError> Session::ListFactions(
    const ListFactionsRequest& req) {
  httplib::Result result = MakeGet(req);
  return ResponseBodyOrError<ListFactionsResponse>(result);
}
Result<GetFactionResponse, RequestError> Session::GetFaction(
    const GetFactionRequest& req) {
  httplib::Result result = MakeGet(req);
  return ResponseBodyOrError<GetFactionResponse>(result);
}

Result<ListShipsResponse, RequestError> Session::ListShips(
    const ListShipsRequest& req) {
  httplib::Result result = MakeAuthGet(req);
  return ResponseBodyOrError<ListShipsResponse>(result);
}
Result<PurchaseShipResponse, RequestError> Session::PurchaseShip(
    const PurchaseShipRequest& req) {
  httplib::Result result = MakeAuthPost(req);
  return ResponseBodyOrError<PurchaseShipResponse>(result);
}
Result<GetShipResponse, RequestError> Session::GetShip(
    const GetShipRequest& req) {
  httplib::Result result = MakeAuthGet(req);
  return ResponseBodyOrError<GetShipResponse>(result);
}
Result<GetShipCargoResponse, RequestError> Session::GetShipCargo(
    const GetShipCargoRequest& req) {
  httplib::Result result = MakeAuthGet(req);
  return ResponseBodyOrError<GetShipCargoResponse>(result);
}
Result<OrbitShipResponse, RequestError> Session::OrbitShip(
    const OrbitShipRequest& req) {
  httplib::Result result = MakeAuthPost(req);
  return ResponseBodyOrError<OrbitShipResponse>(result);
}
Result<ShipRefineResponse, RequestError> Session::ShipRefine(
    const ShipRefineRequest& req) {
  httplib::Result result = MakeAuthPost(req);
  return ResponseBodyOrError<ShipRefineResponse>(result);
}
Result<CreateChartResponse, RequestError> Session::CreateChart(
    const CreateChartRequest& req) {
  httplib::Result result = MakeAuthPost(req);
  return ResponseBodyOrError<CreateChartResponse>(result);
}
Result<GetShipCooldownResponse, RequestError> Session::GetShipCooldown(
    const GetShipCooldownRequest& req) {
  httplib::Result result = MakeAuthGet(req);
  // Special case with two valid response status
  if (result->status != GetShipCooldownResponse::kValidStatus &&
      result->status != GetShipCooldownResponse::kNoCooldownStatus) {
    RequestError err(result->status, result->body);
    return Err(err);
  }

  nlohmann::json j = j.parse(result->body);
  GetShipCooldownResponse response = j.get<GetShipCooldownResponse>();
  return Ok(response);
}
Result<DockShipResponse, RequestError> Session::DockShip(
    const DockShipRequest& req) {
  httplib::Result result = MakeAuthPost(req);
  return ResponseBodyOrError<DockShipResponse>(result);
}
Result<CreateSurveyResponse, RequestError> Session::CreateSurvey(
    const CreateSurveyRequest& req) {
  httplib::Result result = MakeAuthPost(req);
  return ResponseBodyOrError<CreateSurveyResponse>(result);
}
Result<ExtractResourcesResponse, RequestError> Session::ExtractResources(
    const ExtractResourcesRequest& req) {
  httplib::Result result = MakeAuthPost(req);
  return ResponseBodyOrError<ExtractResourcesResponse>(result);
}
Result<JettisonCargoResponse, RequestError> Session::JettisonCargo(
    const JettisonCargoRequest& req) {
  httplib::Result result = MakeAuthPost(req);
  return ResponseBodyOrError<JettisonCargoResponse>(result);
}
Result<JumpShipResponse, RequestError> Session::JumpShip(
    const JumpShipRequest& req) {
  httplib::Result result = MakeAuthPost(req);
  return ResponseBodyOrError<JumpShipResponse>(result);
}
Result<NavigateShipResponse, RequestError> Session::NavigateShip(
    const NavigateShipRequest& req) {
  httplib::Result result = MakeAuthPost(req);
  return ResponseBodyOrError<NavigateShipResponse>(result);
}
Result<PatchShipNavResponse, RequestError> Session::PatchShipNav(
    const PatchShipNavRequest& req) {
  httplib::Result result = MakeAuthPatch(req);
  return ResponseBodyOrError<PatchShipNavResponse>(result);
}
Result<GetShipNavResponse, RequestError> Session::GetShipNav(
    const GetShipNavRequest& req) {
  httplib::Result result = MakeAuthGet(req);
  return ResponseBodyOrError<GetShipNavResponse>(result);
}
Result<WarpShipResponse, RequestError> Session::WarpShip(
    const WarpShipRequest& req) {
  httplib::Result result = MakeAuthPost(req);
  return ResponseBodyOrError<WarpShipResponse>(result);
}
Result<SellCargoResponse, RequestError> Session::SellCargo(
    const SellCargoRequest& req) {
  httplib::Result result = MakeAuthPost(req);
  return ResponseBodyOrError<SellCargoResponse>(result);
}
Result<ScanSystemsResponse, RequestError> Session::ScanSystems(
    const ScanSystemsRequest& req) {
  httplib::Result result = MakeAuthPost(req);
  return ResponseBodyOrError<ScanSystemsResponse>(result);
}
Result<ScanWaypointsResponse, RequestError> Session::ScanWaypoints(
    const ScanWaypointsRequest& req) {
  httplib::Result result = MakeAuthPost(req);
  return ResponseBodyOrError<ScanWaypointsResponse>(result);
}
Result<ScanShipsResponse, RequestError> Session::ScanShips(
    const ScanShipsRequest& req) {
  httplib::Result result = MakeAuthPost(req);
  return ResponseBodyOrError<ScanShipsResponse>(result);
}
Result<RefuelShipResponse, RequestError> Session::RefuelShip(
    const RefuelShipRequest& req) {
  httplib::Result result = MakeAuthPost(req);
  return ResponseBodyOrError<RefuelShipResponse>(result);
}
Result<PurchaseCargoResponse, RequestError> Session::PurchaseCargo(
    const PurchaseCargoRequest& req) {
  httplib::Result result = MakeAuthPost(req);
  return ResponseBodyOrError<PurchaseCargoResponse>(result);
}
Result<TransferCargoResponse, RequestError> Session::TransferCargo(
    const TransferCargoRequest& req) {
  httplib::Result result = MakeAuthPost(req);
  return ResponseBodyOrError<TransferCargoResponse>(result);
}
Result<NegotiateContractResponse, RequestError> Session::NegotiateContract(
    const NegotiateContractRequest& req) {
  httplib::Result result = MakeAuthPost(req);
  return ResponseBodyOrError<NegotiateContractResponse>(result);
}
Result<GetMountsResponse, RequestError> Session::GetMounts(
    const GetMountsRequest& req) {
  httplib::Result result = MakeAuthGet(req);
  return ResponseBodyOrError<GetMountsResponse>(result);
}
Result<InstallMountResponse, RequestError> Session::InstallMounts(
    const InstallMountRequest& req) {
  httplib::Result result = MakeAuthPost(req);
  return ResponseBodyOrError<InstallMountResponse>(result);
}
Result<RemoveMountResponse, RequestError> Session::RemoveMounts(
    const RemoveMountRequest& req) {
  httplib::Result result = MakeAuthPost(req);
  return ResponseBodyOrError<RemoveMountResponse>(result);
}

Result<ListSystemsResponse, RequestError> Session::ListSystems(
    const ListSystemsRequest& req) {
  httplib::Result result = MakeGet(req);
  return ResponseBodyOrError<ListSystemsResponse>(result);
}
Result<GetSystemResponse, RequestError> Session::GetSystem(
    const GetSystemRequest& req) {
  httplib::Result result = MakeGet(req);
  return ResponseBodyOrError<GetSystemResponse>(result);
}
Result<ListWaypointsResponse, RequestError> Session::ListWaypoints(
    const ListWaypointsRequest& req) {
  httplib::Result result = MakeGet(req);
  return ResponseBodyOrError<ListWaypointsResponse>(result);
}
Result<GetWaypointResponse, RequestError> Session::GetWaypoint(
    const GetWaypointRequest& req) {
  httplib::Result result = MakeGet(req);
  return ResponseBodyOrError<GetWaypointResponse>(result);
}
Result<GetMarketResponse, RequestError> Session::GetMarket(
    const GetMarketRequest& req) {
  httplib::Result result = MakeGet(req);
  return ResponseBodyOrError<GetMarketResponse>(result);
}
Result<GetShipyardResponse, RequestError> Session::GetShipyard(
    const GetShipyardRequest& req) {
  httplib::Result result = MakeGet(req);
  return ResponseBodyOrError<GetShipyardResponse>(result);
}
Result<GetJumpGateResponse, RequestError> Session::GetJumpGate(
    const GetJumpGateRequest& req) {
  httplib::Result result = MakeGet(req);
  return ResponseBodyOrError<GetJumpGateResponse>(result);
}

Result<MyAgentResponse, RequestError> Session::MyAgent(
    const MyAgentRequest& req) {
  httplib::Result result = MakeAuthGet(req);
  return ResponseBodyOrError<MyAgentResponse>(result);
}