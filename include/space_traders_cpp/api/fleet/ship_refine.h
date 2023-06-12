#pragma once

#include "cpp-httplib/httplib.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/cooldown.h"
#include "space_traders_cpp/models/ship_cargo.h"
#include "space_traders_cpp/utility.h"

enum class ShipRefineProduce {
  IRON,
  COPPER,
  SILVER,
  GOLD,
  ALUMINIUM,
  PLATINUM,
  URANITE,
  MERITIUM,
  FUEL,
};
NLOHMANN_JSON_SERIALIZE_ENUM(ShipRefineProduce,
                             {
                                 {ShipRefineProduce::IRON, "IRON"},
                                 {ShipRefineProduce::COPPER, "COPPER"},
                                 {ShipRefineProduce::SILVER, "SILVER"},
                                 {ShipRefineProduce::GOLD, "GOLD"},
                                 {ShipRefineProduce::ALUMINIUM, "ALUMINIUM"},
                                 {ShipRefineProduce::PLATINUM, "PLATINUM"},
                                 {ShipRefineProduce::URANITE, "URANITE"},
                                 {ShipRefineProduce::MERITIUM, "MERITIUM"},
                                 {ShipRefineProduce::FUEL, "FUEL"},
                             })

struct ShipRefineRequest {
 public:
  struct PathParams {
    std::string shipSymbol;
  };
  struct QueryParams {};
  struct Body {
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
