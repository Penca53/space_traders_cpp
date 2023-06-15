#pragma once

#include "nlohmann/json.hpp"

enum class SystemType {
  kNeutronStar,
  kRedStar,
  kOrangeStar,
  kBlueStar,
  kYoungStar,
  kWhiteDwarf,
  kBlackHole,
  kHypergiant,
  kNebula,
  kUnstable,
};
NLOHMANN_JSON_SERIALIZE_ENUM(SystemType,
                             {
                                 {SystemType::kNeutronStar, "NEUTRON_STAR"},
                                 {SystemType::kRedStar, "RED_STAR"},
                                 {SystemType::kOrangeStar, "ORANGE_STAR"},
                                 {SystemType::kBlueStar, "BLUE_STAR"},
                                 {SystemType::kYoungStar, "YOUNG_STAR"},
                                 {SystemType::kWhiteDwarf, "WHITE_DWARF"},
                                 {SystemType::kBlackHole, "BLACK_HOLE"},
                                 {SystemType::kHypergiant, "HYPERGIANT"},
                                 {SystemType::kNebula, "NEBULA"},
                                 {SystemType::kUnstable, "UNSTABLE"},
                             })
