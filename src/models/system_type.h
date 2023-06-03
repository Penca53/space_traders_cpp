#pragma once

#include <third_party/json.h>

enum class SystemType {
  NEUTRON_STAR,
  RED_STAR,
  ORANGE_STAR,
  BLUE_STAR,
  YOUNG_STAR,
  WHITE_DWARF,
  BLACK_HOLE,
  HYPERGIANT,
  NEBULA,
  UNSTABLE
};
NLOHMANN_JSON_SERIALIZE_ENUM(SystemType,
                             {
                                 {SystemType::NEUTRON_STAR, "NEUTRON_STAR"},
                                 {SystemType::RED_STAR, "RED_STAR"},
                                 {SystemType::ORANGE_STAR, "ORANGE_STAR"},
                                 {SystemType::BLUE_STAR, "BLUE_STAR"},
                                 {SystemType::YOUNG_STAR, "YOUNG_STAR"},
                                 {SystemType::WHITE_DWARF, "WHITE_DWARF"},
                                 {SystemType::BLACK_HOLE, "BLACK_HOLE"},
                                 {SystemType::HYPERGIANT, "HYPERGIANT"},
                                 {SystemType::NEBULA, "NEBULA"},
                                 {SystemType::UNSTABLE, "UNSTABLE"},
                             })