#pragma once

#include "nlohmann/json.hpp"

#include "space_traders_cpp/models/contract_terms.h"

struct Contract {
 public:
  friend void to_json(nlohmann::json& j, const Contract& c) {
    j["id"] = c.id;
    j["factionSymbol"] = c.factionSymbol;
    j["type"] = c.type;
    j["terms"] = c.terms;
    j["accepted"] = c.accepted;
    j["fulfilled"] = c.fulfilled;
    j["deadlineToAccept"] = c.deadlineToAccept;
  }
  friend void from_json(const nlohmann::json& j, Contract& c) {
    j.at("id").get_to(c.id);
    j.at("factionSymbol").get_to(c.factionSymbol);
    j.at("type").get_to(c.type);
    j.at("terms").get_to(c.terms);
    j.at("accepted").get_to(c.accepted);
    j.at("fulfilled").get_to(c.fulfilled);
    if (j.contains("deadlineToAccept")) {
      j.at("deadlineToAccept").get_to(c.deadlineToAccept);
    }
  }

 public:
  std::string id;
  std::string factionSymbol;
  std::string type;
  ContractTerms terms{};
  bool accepted = false;
  bool fulfilled = false;
  std::optional<std::string> deadlineToAccept;
};