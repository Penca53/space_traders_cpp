#pragma once

#include "json.h"

#include "models/contract_deliver_good.h"
#include "models/contract_payment.h"
#include "utility.h"

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
  std::string deadline;
  ContractPayment payment{};
  std::optional<std::vector<ContractDeliverGood>> deliver;
};