#pragma once

#include "nlohmann/json.hpp"

#include "space_traders_cpp/models/faction_trait.h"

struct Faction {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(Faction, symbol, name, description,
                                 headquarters, traits, isRecruiting)

 public:
  std::string symbol;
  std::string name;
  std::string description;
  std::string headquarters;
  std::vector<FactionTrait> traits;
  bool isRecruiting = false;
};