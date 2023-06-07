#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/utility.h"

struct StatusRequest {
 public:
  struct PathParams {};
  struct QueryParams {};
  struct Body {};

 public:
  explicit StatusRequest() = default;
  explicit StatusRequest(PathParams path_params, QueryParams query_params,
                         Body body);

 public:
  std::string FormattedPath() const;
  httplib::Params HttplibParams() const;

 public:
  static const std::string kRelativePath;

 public:
  PathParams path_params{};
  QueryParams query_params{};
  Body body{};
};

struct StatusResponse {
 private:
  struct Stats {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Stats, agents, ships, systems, waypoints)

   public:
    int64_t agents = 0;
    int64_t ships = 0;
    int64_t systems = 0;
    int64_t waypoints = 0;
  };

  struct Leaderboards {
    struct Credits {
     public:
      NLOHMANN_DEFINE_TYPE_INTRUSIVE(Credits, agentSymbol, credits)

     public:
      std::string agentSymbol;
      int64_t credits = 0;
    };

    struct SubmittedChart {
     public:
      NLOHMANN_DEFINE_TYPE_INTRUSIVE(SubmittedChart, agentSymbol, chartCount)

     public:
      std::string agentSymbol;
      int64_t chartCount = 0;
    };

   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Leaderboards, mostCredits,
                                   mostSubmittedCharts)

   public:
    std::vector<Credits> mostCredits;
    std::vector<SubmittedChart> mostSubmittedCharts;
  };

  struct ServerResets {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(ServerResets, next, frequency)

   public:
    std::string next;
    std::string frequency;
  };

  struct Announcement {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Announcement, title, body)

   public:
    std::string title;
    std::string body;
  };

  struct Link {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Link, name, url)

   public:
    std::string name;
    std::string url;
  };

 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(StatusResponse, status, version, resetDate,
                                 description, stats, leaderboards, serverResets,
                                 announcements, links)

 public:
  static constexpr int32_t kValidStatus = kGetOkStatus;

 public:
  std::string status;
  std::string version;
  std::string resetDate;
  std::string description;
  Stats stats{};
  Leaderboards leaderboards{};
  ServerResets serverResets{};
  std::vector<Announcement> announcements;
  std::vector<Link> links;
};
