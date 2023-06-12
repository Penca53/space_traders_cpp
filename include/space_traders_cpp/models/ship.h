#pragma once

#include "nlohmann/json.hpp"

#include "space_traders_cpp/models/ship_cargo.h"
#include "space_traders_cpp/models/ship_crew.h"
#include "space_traders_cpp/models/ship_engine.h"
#include "space_traders_cpp/models/ship_frame.h"
#include "space_traders_cpp/models/ship_fuel.h"
#include "space_traders_cpp/models/ship_module.h"
#include "space_traders_cpp/models/ship_mount.h"
#include "space_traders_cpp/models/ship_nav.h"
#include "space_traders_cpp/models/ship_reactor.h"
#include "space_traders_cpp/models/ship_registration.h"

struct Ship {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(Ship, symbol, registration, nav, crew, frame,
                                 reactor, engine, modules, mounts, cargo, fuel)

public:
  bool operator==(const Ship&) const = default;

 public:
  std::string symbol;
  ShipRegistration registration{};
  ShipNav nav{};
  ShipCrew crew{};
  ShipFrame frame{};
  ShipReactor reactor{};
  ShipEngine engine{};
  std::vector<ShipModule> modules;
  std::vector<ShipMount> mounts;
  ShipCargo cargo{};
  ShipFuel fuel{};
};