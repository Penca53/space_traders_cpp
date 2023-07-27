#pragma once

#include "httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/cooldown.h"
#include "space_traders_cpp/models/ship_cargo.h"
#include "space_traders_cpp/utility.h"

enum class ShipRefineProduce {
  kIron,
  kCopper,
  kSilver,
  kGold,
  kAluminium,
  kPlatinum,
  kUranite,
  kMeritium,
  kFuel,
};
NLOHMANN_JSON_SERIALIZE_ENUM(ShipRefineProduce,
                             {
                                 {ShipRefineProduce::kIron, "IRON"},
                                 {ShipRefineProduce::kCopper, "COPPER"},
                                 {ShipRefineProduce::kSilver, "SILVER"},
                                 {ShipRefineProduce::kGold, "GOLD"},
                                 {ShipRefineProduce::kAluminium, "ALUMINIUM"},
                                 {ShipRefineProduce::kPlatinum, "PLATINUM"},
                                 {ShipRefineProduce::kUranite, "URANITE"},
                                 {ShipRefineProduce::kMeritium, "MERITIUM"},
                                 {ShipRefineProduce::kFuel, "FUEL"},
                             })

struct ShipRefineRequest {
 public:
  struct PathParams {
    std::string shipSymbol;
  };
  struct QueryParams {};
  struct Body {
   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Body, produce)

   public:
    ShipRefineProduce produce{};
  };

 public:
  explicit ShipRefineRequest() = default;
  explicit ShipRefineRequest(PathParams path_params, QueryParams query_params,
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

struct ShipRefineResponse {
  struct Data {
    struct RefineMaterial {
     public:
      NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(RefineMaterial, tradeSymbol,
                                                  units)

     public:
      bool operator==(const RefineMaterial&) const = default;

     public:
      std::optional<std::string> tradeSymbol;
      std::optional<int64_t> units;
    };

   public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Data, cargo, cooldown, produced, consumed)

   public:
    bool operator==(const Data&) const = default;

   public:
    ShipCargo cargo{};
    Cooldown cooldown{};
    std::vector<RefineMaterial> produced;
    std::vector<RefineMaterial> consumed;
  };

 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShipRefineResponse, data)

 public:
  bool operator==(const ShipRefineResponse&) const = default;

 public:
  static constexpr int32_t kValidStatus = kHttpOkStatus;

 public:
  Data data{};
  int32_t http_status = 0;
};
