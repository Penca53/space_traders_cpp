#pragma once

#include "json.h"
#include "space_traders_cpp/models/agent.h"
#include "space_traders_cpp/models/contract.h"
#include "space_traders_cpp/models/faction.h"
#include "space_traders_cpp/utility.h"

struct RegisterRequest {
 public:
  struct PathParams {};
  struct QueryParams {};
  struct Body {
   public:
    friend void to_json(nlohmann::json& j, const Body& b) {
      j["faction"] = b.faction;
      j["symbol"] = b.symbol;
      j["email"] = b.email;
    }
    friend void from_json(const nlohmann::json& j, Body& b) {
      j.at("faction").get_to(b.faction);
      j.at("symbol").get_to(b.symbol);
      if (j.contains("email")) {
        j.at("email").get_to(b.email);
      }
    }

   public:
    std::string faction;
    std::string symbol;
    std::optional<std::string> email;
  };

 public:
  explicit RegisterRequest() = default;
  explicit RegisterRequest(PathParams path_params, QueryParams query_params,
                           Body body);

 public:
  std::string FormattedPath() const;

 public:
  static const std::string kRelativePath;

 public:
  PathParams path_params{};
  QueryParams query_params{};
  Body body{};
};

struct RegisterResponse {
 private:
  struct RegisterData {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(RegisterData, agent, contract, faction,
                                   token)
   public:
    Agent agent;
    Contract contract;
    Faction faction;
    std::string token;
  };

 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(RegisterResponse, data)

 public:
  static constexpr int32_t kValidStatus = kPostOkStatus;

 public:
  RegisterData data{};
};