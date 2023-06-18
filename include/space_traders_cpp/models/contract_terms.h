#pragma once

#include "nlohmann/json.hpp"
#include "space_traders_cpp/models/contract_deliver_good.h"
#include "space_traders_cpp/models/contract_payment.h"
#include "space_traders_cpp/utility.h"

struct ContractTerms {
 public:
  friend void to_json(nlohmann::json& j, const ContractTerms& ct) {
    j["deadline"] = ct.deadline;
    j["payment"] = ct.payment;
    j["deliver"] = ct.deliver;
  }
  friend void from_json(const nlohmann::json& j, ContractTerms& ct) {
    j.at("deadline").get_to(ct.deadline);
    j.at("payment").get_to(ct.payment);
    if (j.contains("deliver")) {
      j.at("deliver").get_to(ct.deliver);
    }
  }

 public:
  bool operator==(const ContractTerms&) const = default;

 public:
  DateTime deadline;
  ContractPayment payment{};
  std::optional<std::vector<ContractDeliverGood>> deliver;
};