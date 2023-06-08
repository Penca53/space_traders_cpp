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
    const GetShipCargoRequest& req) {}
Result<OrbitShipResponse, RequestError> Session::OrbitShip(
    const OrbitShipRequest& req) {}
Result<ShipRefineResponse, RequestError> Session::ShipRefine(
    const ShipRefineRequest& req) {}
Result<CreateChartResponse, RequestError> Session::CreateChart(
    const CreateChartRequest& req) {}
Result<GetShipCooldownResponse, RequestError> Session::GetShipCooldown(
    const GetShipCooldownRequest& req) {}
Result<DockShipResponse, RequestError> Session::DockShip(
    const DockShipRequest& req) {}
Result<CreateSurveyResponse, RequestError> Session::CreateSurvey(
    const CreateSurveyRequest& req) {}
Result<ExtractResourcesResponse, RequestError> Session::ExtractResources(
    const ExtractResourcesRequest& req) {}
Result<JettisonCargoResponse, RequestError> Session::JettisonCargo(
    const JettisonCargoRequest& req) {}
Result<JumpShipResponse, RequestError> Session::JumpShip(
    const JumpShipRequest& req) {}
Result<NavigateShipResponse, RequestError> Session::NavigateShip(
    const NavigateShipRequest& req) {}
Result<PatchShipNavResponse, RequestError> Session::PatchShipNav(
    const PatchShipNavRequest& req) {}
Result<GetShipNavResponse, RequestError> Session::GetShipNav(
    const GetShipNavRequest& req) {}
Result<WarpShipResponse, RequestError> Session::WarpShip(
    const WarpShipRequest& req) {}
Result<SellCargoResponse, RequestError> Session::SellCargo(
    const SellCargoRequest& req) {}
Result<ScanSystemsResponse, RequestError> Session::ScanSystems(
    const ScanSystemsRequest& req) {}
Result<ScanWaypointsResponse, RequestError> Session::ScanWaypoints(
    const ScanWaypointsRequest& req) {}
Result<ScanShipsResponse, RequestError> Session::ScanShips(
    const ScanShipsRequest& req) {}
Result<RefuelShipResponse, RequestError> Session::RefuelShip(
    const RefuelShipRequest& req) {}
Result<PurchaseCargoResponse, RequestError> Session::PurchaseCargo(
    const PurchaseCargoRequest& req) {}
Result<TransferCargoResponse, RequestError> Session::TransferCargo(
    const TransferCargoRequest& req) {}
Result<NegotiateContractResponse, RequestError> Session::NegotiateContract(
    const NegotiateContractRequest& req) {}
Result<GetMountsResponse, RequestError> Session::GetMounts(
    const GetMountsRequest& req) {}
Result<InstallMountResponse, RequestError> Session::InstallMounts(
    const InstallMountRequest& req) {}
Result<RemoveMountResponse, RequestError> Session::RemoveMounts(
    const RemoveMountRequest& req) {}

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