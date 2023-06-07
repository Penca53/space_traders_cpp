#include "space_traders_cpp/session.h"

#include "space_traders_cpp/utility.h"

using json = nlohmann::json;

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
  httplib::Result result = MakeGet(kBasePath + req.FormattedPath());
  if (result->status != StatusResponse::kValidStatus) {
    RequestError err(result->status, result->body);
    return Err(err);
  }

  json j = j.parse(result->body);
  StatusResponse status_response = j.get<StatusResponse>();
  return Ok(status_response);
}
Result<RegisterResponse, RequestError> Session::Register(
    const RegisterRequest& req) {
  json j = req.body;
  httplib::Result result = MakePost(kBasePath + req.FormattedPath(), j.dump());
  if (result->status != RegisterResponse::kValidStatus) {
    RequestError err(result->status, result->body);
    return Err(err);
  }

  j = j.parse(result->body);
  RegisterResponse register_response = j.get<RegisterResponse>();
  return Ok(register_response);
}
Result<ListFactionsResponse, RequestError> Session::ListFactions(
    const ListFactionsRequest& req) {
  httplib::Result result =
      MakeGet(kBasePath + req.FormattedPath(), req.HttplibParams());

  if (result->status != ListFactionsResponse::kValidStatus) {
    RequestError err(result->status, result->body);
    return Err(err);
  }

  json j = j.parse(result->body);
  ListFactionsResponse list_factions_response = j.get<ListFactionsResponse>();
  return Ok(list_factions_response);
}
Result<GetFactionResponse, RequestError> Session::GetFaction(
    const GetFactionRequest& req) {
  httplib::Result result = MakeGet(kBasePath + req.FormattedPath());
  if (result->status != GetFactionResponse::kValidStatus) {
    RequestError err(result->status, result->body);
    return Err(err);
  }

  json j = j.parse(result->body);
  GetFactionResponse get_faction_response = j.get<GetFactionResponse>();
  return Ok(get_faction_response);
}

Result<ListSystemsResponse, RequestError> Session::ListSystems(
    const ListSystemsRequest& req) {
  httplib::Result result =
      MakeGet(kBasePath + req.FormattedPath(), req.HttplibParams());

  if (result->status != ListSystemsResponse::kValidStatus) {
    RequestError err(result->status, result->body);
    return Err(err);
  }

  json j = j.parse(result->body);
  ListSystemsResponse list_systems_response = j.get<ListSystemsResponse>();
  return Ok(list_systems_response);
}
Result<GetSystemResponse, RequestError> Session::GetSystem(
    const GetSystemRequest& req) {
  httplib::Result result = MakeGet(kBasePath + req.FormattedPath());
  if (result->status != GetSystemResponse::kValidStatus) {
    RequestError err(result->status, result->body);
    return Err(err);
  }

  json j = j.parse(result->body);
  GetSystemResponse get_system_response = j.get<GetSystemResponse>();
  return Ok(get_system_response);
}
Result<ListWaypointsResponse, RequestError> Session::ListWaypoints(
    const ListWaypointsRequest& req) {
  httplib::Result result =
      MakeGet(kBasePath + req.FormattedPath(), req.HttplibParams());

  if (result->status != ListWaypointsResponse::kValidStatus) {
    RequestError err(result->status, result->body);
    return Err(err);
  }

  json j = j.parse(result->body);
  ListWaypointsResponse list_waypoints_response =
      j.get<ListWaypointsResponse>();
  return Ok(list_waypoints_response);
}
Result<GetWaypointResponse, RequestError> Session::GetWaypoint(
    const GetWaypointRequest& req) {
  httplib::Result result = MakeGet(kBasePath + req.FormattedPath());
  if (result->status != GetWaypointResponse::kValidStatus) {
    RequestError err(result->status, result->body);
    return Err(err);
  }

  json j = j.parse(result->body);
  GetWaypointResponse get_waypoint_response = j.get<GetWaypointResponse>();
  return Ok(get_waypoint_response);
}
Result<GetMarketResponse, RequestError> Session::GetMarket(
    const GetMarketRequest& req) {
  httplib::Result result = MakeGet(kBasePath + req.FormattedPath());
  if (result->status != GetMarketResponse::kValidStatus) {
    RequestError err(result->status, result->body);
    return Err(err);
  }

  json j = j.parse(result->body);
  GetMarketResponse get_market_response = j.get<GetMarketResponse>();
  return Ok(get_market_response);
}
Result<GetShipyardResponse, RequestError> Session::GetShipyard(
    const GetShipyardRequest& req) {
  httplib::Result result = MakeGet(kBasePath + req.FormattedPath());
  if (result->status != GetShipyardResponse::kValidStatus) {
    RequestError err(result->status, result->body);
    return Err(err);
  }

  json j = j.parse(result->body);
  GetShipyardResponse get_shipyard_response = j.get<GetShipyardResponse>();
  return Ok(get_shipyard_response);
}
Result<GetJumpGateResponse, RequestError> Session::GetJumpGate(
    const GetJumpGateRequest& req) {
  httplib::Result result = MakeGet(kBasePath + req.FormattedPath());
  if (result->status != GetJumpGateResponse::kValidStatus) {
    RequestError err(result->status, result->body);
    return Err(err);
  }

  json j = j.parse(result->body);
  GetJumpGateResponse get_jump_gate_response = j.get<GetJumpGateResponse>();
  return Ok(get_jump_gate_response);
}

Result<MyAgentResponse, RequestError> Session::MyAgent(
    const MyAgentRequest& req) {
  httplib::Result result = MakeAuthGet(kBasePath + req.FormattedPath());
  if (result->status != MyAgentResponse::kValidStatus) {
    RequestError err(result->status, result->body);
    return Err(err);
  }

  json j = j.parse(result->body);
  MyAgentResponse my_agent_response = j.get<MyAgentResponse>();
  return Ok(my_agent_response);
}

httplib::Result Session::MakeGet(std::string path) { return client_.Get(path); }
httplib::Result Session::MakeGet(std::string path, httplib::Params params) {
  return client_.Get(path, params, httplib::Headers{});
}
httplib::Result Session::MakePost(std::string path, std::string body,
                                  std::string content_type) {
  return client_.Post(path, body, content_type);
}

httplib::Result Session::MakeAuthGet(std::string path) {
  return client_.Get(path,
                     httplib::Headers{{"Authorization", "Bearer " + token_}});
}
httplib::Result Session::MakeAuthGet(std::string path, httplib::Params params) {
  return client_.Get(path, params,
                     httplib::Headers{{"Authorization", "Bearer " + token_}});
}
httplib::Result Session::MakeAuthPost(std::string path, std::string body,
                                      std::string content_type) {
  return client_.Post(path,
                      httplib::Headers{{"Authorization", "Bearer " + token_}},
                      body, content_type);
}