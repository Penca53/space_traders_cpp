#pragma once

#include <httplib.h>
#include <json.h>

#include "api/agents/my_agent.h"
#include "api/factions/get_faction.h"
#include "api/factions/list_factions.h"
#include "api/register.h"
#include "api/status.h"
#include "api/systems/get_system.h"
#include "api/systems/get_waypoint.h"
#include "api/systems/list_systems.h"
#include "api/systems/list_waypoints.h"
#include "utility.h"

struct LoginRequest {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(LoginRequest, token)

 public:
  std::string token;
};

struct RequestError {
 public:
  explicit RequestError(int32_t status, std::string body)
      : status(status), body(body) {}

 public:
  int32_t status = -1;
  std::string body;
};

class Session {
 public:
  explicit Session();
  explicit Session(std::string token);

  bool IsAPIOnline();
  bool IsLoggedIn();

  Result<MyAgentResponse, RequestError> Login(LoginRequest& req);

  Result<StatusResponse, RequestError> Status();
  Result<RegisterResponse, RequestError> Register(RegisterRequest& req);
  Result<ListFactionsResponse, RequestError> ListFactions(
      ListFactionsRequest& req);
  Result<GetFactionResponse, RequestError> GetFaction(GetFactionRequest& req);
  Result<ListSystemsResponse, RequestError> ListSystems(
      ListSystemsRequest& req);
  Result<GetSystemResponse, RequestError> GetSystem(GetSystemRequest& req);
  Result<ListWaypointsResponse, RequestError> ListWaypoints(
      ListWaypointsRequest& req);
  Result<GetWaypointResponse, RequestError> GetWaypoint(
      GetWaypointRequest& req);
  Result<MyAgentResponse, RequestError> MyAgent();

 private:
  httplib::Result MakeGet(std::string path);
  httplib::Result MakeGet(std::string path, httplib::Params params);
  httplib::Result MakePost(std::string path, std::string body,
                           std::string content_type = "application/json");

  httplib::Result MakeAuthGet(std::string path);
  httplib::Result MakeAuthGet(std::string path, httplib::Params params);
  httplib::Result MakeAuthPost(std::string path, std::string body,
                               std::string content_type = "application/json");

 private:
  std::string token_;
  httplib::Client client_;
};