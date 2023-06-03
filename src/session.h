#pragma once

#include <third_party/httplib.h>
#include <third_party/json.h>

#include "src/api/agents/my_agent.h"
#include "src/api/factions/get_faction.h"
#include "src/api/factions/list_factions.h"
#include "src/api/register.h"
#include "src/api/status.h"
#include "src/api/systems/get_system.h"
#include "src/api/systems/get_waypoint.h"
#include "src/api/systems/list_systems.h"
#include "src/api/systems/list_waypoints.h"
#include "src/utility.h"

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