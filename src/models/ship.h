#pragma once

#include <third_party/json.h>

#include "src/models/ship_cargo.h"
#include "src/models/ship_crew.h"
#include "src/models/ship_engine.h"
#include "src/models/ship_frame.h"
#include "src/models/ship_fuel.h"
#include "src/models/ship_module.h"
#include "src/models/ship_mount.h"
#include "src/models/ship_nav.h"
#include "src/models/ship_reactor.h"
#include "src/models/ship_registration.h"

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