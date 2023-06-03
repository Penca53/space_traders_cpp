#include "space_traders_cpp/session.h"

#include "space_traders_cpp/utility.h"

using json = nlohmann::json;

Session::Session() : client_("https://api.spacetraders.io") {}
Session::Session(std::string token)
    : token_(token), client_("https://api.spacetraders.io") {}

bool Session::IsAPIOnline() {
  auto status_res = Status();
  if (status_res.IsErr()) {
    return false;
  }
  return status_res.Ok().status.find("online") != std::string::npos;
}
bool Session::IsLoggedIn() { return MyAgent().IsOk(); }

Result<MyAgentResponse, RequestError> Session::Login(LoginRequest& req) {
  token_ = req.token;
  return MyAgent();
}
Result<StatusResponse, RequestError> Session::Status() {
  httplib::Result result = MakeGet("/v2/");
  if (result->status != 200) {
    RequestError err(result->status, result->body);
    return Err(err);
  }

  json j = j.parse(result->body);
  StatusResponse status_response = j.get<StatusResponse>();
  return Ok(status_response);
}
Result<RegisterResponse, RequestError> Session::Register(RegisterRequest& req) {
  json j = req;
  httplib::Result result = MakePost("/v2/register", j.dump());
  if (result->status != 201) {
    RequestError err(result->status, result->body);
    return Err(err);
  }

  j = j.parse(result->body);
  RegisterResponse register_response = j.get<RegisterResponse>();
  return Ok(register_response);
}
Result<ListFactionsResponse, RequestError> Session::ListFactions(
    ListFactionsRequest& req) {
  httplib::Result result = MakeGet(
      "/v2/factions", httplib::Params{{"limit", std::to_string(req.limit)},
                                      {"page", std::to_string(req.page)}});

  if (result->status != 200) {
    RequestError err(result->status, result->body);
    return Err(err);
  }

  json j = j.parse(result->body);
  ListFactionsResponse list_factions_response = j.get<ListFactionsResponse>();
  return Ok(list_factions_response);
}
Result<GetFactionResponse, RequestError> Session::GetFaction(
    GetFactionRequest& req) {
  httplib::Result result = MakeGet("/v2/factions/" + req.factionSymbol);
  if (result->status != 200) {
    RequestError err(result->status, result->body);
    return Err(err);
  }

  json j = j.parse(result->body);
  GetFactionResponse get_faction_response = j.get<GetFactionResponse>();
  return Ok(get_faction_response);
}

Result<ListSystemsResponse, RequestError> Session::ListSystems(
    ListSystemsRequest& req) {
  httplib::Result result = MakeGet(
      "/v2/systems", httplib::Params{{"limit", std::to_string(req.limit)},
                                     {"page", std::to_string(req.page)}});

  if (result->status != 200) {
    RequestError err(result->status, result->body);
    return Err(err);
  }

  json j = j.parse(result->body);
  try {
    ListSystemsResponse list_systems_response = j.get<ListSystemsResponse>();
    return Ok(list_systems_response);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return Ok(ListSystemsResponse{});
  }
}
Result<GetSystemResponse, RequestError> Session::GetSystem(
    GetSystemRequest& req) {
  httplib::Result result = MakeGet("/v2/systems/" + req.systemSymbol);
  if (result->status != 200) {
    RequestError err(result->status, result->body);
    return Err(err);
  }

  json j = j.parse(result->body);
  GetSystemResponse get_system_response = j.get<GetSystemResponse>();
  return Ok(get_system_response);
}
Result<ListWaypointsResponse, RequestError> Session::ListWaypoints(
    ListWaypointsRequest& req) {
  httplib::Result result =
      MakeGet("/v2/systems/" + req.systemSymbol + "/waypoints",
              httplib::Params{{"limit", std::to_string(req.limit)},
                              {"page", std::to_string(req.page)}});

  if (result->status != 200) {
    RequestError err(result->status, result->body);
    return Err(err);
  }

  json j = j.parse(result->body);
  ListWaypointsResponse list_waypoints_response =
      j.get<ListWaypointsResponse>();
  return Ok(list_waypoints_response);
}
Result<GetWaypointResponse, RequestError> Session::GetWaypoint(
    GetWaypointRequest& req) {
  httplib::Result result = MakeGet("/v2/systems/" + req.systemSymbol +
                                   "/waypoints/" + req.waypointSymbol);
  if (result->status != 200) {
    RequestError err(result->status, result->body);
    return Err(err);
  }

  json j = j.parse(result->body);
  GetWaypointResponse get_waypoint_response = j.get<GetWaypointResponse>();
  return Ok(get_waypoint_response);
}

Result<MyAgentResponse, RequestError> Session::MyAgent() {
  httplib::Result result = MakeAuthGet("/v2/my/agent");
  if (result->status != 200) {
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