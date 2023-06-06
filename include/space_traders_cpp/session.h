#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/api/agents/my_agent.h"
#include "space_traders_cpp/api/factions/get_faction.h"
#include "space_traders_cpp/api/factions/list_factions.h"
#include "space_traders_cpp/api/register.h"
#include "space_traders_cpp/api/status.h"
#include "space_traders_cpp/api/systems/get_jump_gate.h"
#include "space_traders_cpp/api/systems/get_market.h"
#include "space_traders_cpp/api/systems/get_shipyard.h"
#include "space_traders_cpp/api/systems/get_system.h"
#include "space_traders_cpp/api/systems/get_waypoint.h"
#include "space_traders_cpp/api/systems/list_systems.h"
#include "space_traders_cpp/api/systems/list_waypoints.h"
#include "space_traders_cpp/utility.h"

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

  Result<MyAgentResponse, RequestError> Login(const LoginRequest& req);

  Result<StatusResponse, RequestError> Status(const StatusRequest& req);
  Result<RegisterResponse, RequestError> Register(const RegisterRequest& req);
  Result<ListFactionsResponse, RequestError> ListFactions(
      const ListFactionsRequest& req);
  Result<GetFactionResponse, RequestError> GetFaction(
      const GetFactionRequest& req);
  Result<ListSystemsResponse, RequestError> ListSystems(
      const ListSystemsRequest& req);
  Result<GetSystemResponse, RequestError> GetSystem(
      const GetSystemRequest& req);
  Result<ListWaypointsResponse, RequestError> ListWaypoints(
      const ListWaypointsRequest& req);
  Result<GetWaypointResponse, RequestError> GetWaypoint(
      const GetWaypointRequest& req);
  Result<GetMarketResponse, RequestError> GetMarket(
      const GetMarketRequest& req);
  Result<GetShipyardResponse, RequestError> GetShipyard(
      const GetShipyardRequest& req);
  Result<GetJumpGateResponse, RequestError> GetJumpGate(
      const GetJumpGateRequest& req);
  Result<MyAgentResponse, RequestError> MyAgent(const MyAgentRequest& req);

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
  static const std::string kBasePath;
};