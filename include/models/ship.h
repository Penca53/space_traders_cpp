#pragma once

#include "json.h"

#include "models/ship_cargo.h"
#include "models/ship_crew.h"
#include "models/ship_engine.h"
#include "models/ship_frame.h"
#include "models/ship_fuel.h"
#include "models/ship_module.h"
#include "models/ship_mount.h"
#include "models/ship_nav.h"
#include "models/ship_reactor.h"
#include "models/ship_registration.h"

struct Ship {
 public:
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(Ship, symbol, registration, nav, crew, frame,
                                 reactor, engine, modules, mounts, cargo, fuel)

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