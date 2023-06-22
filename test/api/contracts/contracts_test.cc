#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/mock_client.h"
#include "space_traders_cpp/session.h"
#include "space_traders_cpp/utility.h"
#include "space_traders_cpp_test/api_test.h"

using ::testing::_;
using ::testing::AtLeast;
using ::testing::ByRef;
using ::testing::Eq;
using ::testing::Return;

TEST(ListContracts, ShouldReturnOkWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);

  const ListContractsResponse expected_list_contracts =
      MakeResponse<ListContractsResponse>();
  httplib::Result expected_result = MakeResultOk(expected_list_contracts);
  EXPECT_CALL(*mock_client, Get("/v2/my/contracts", _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<ListContractsResponse, RequestError> result =
      session.ListContracts(ListContractsRequest{});
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_list_contracts);
}

TEST(GetContractTest, ShouldReturnOkWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_contract = "my-contract";

  GetContractResponse expected_get_contract =
      MakeResponse<GetContractResponse>();
  expected_get_contract.data.id = my_contract;
  httplib::Result expected_result = MakeResultOk(expected_get_contract);
  EXPECT_CALL(*mock_client, Get("/v2/my/contracts/" + my_contract, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<GetContractResponse, RequestError> result = session.GetContract(
      GetContractRequest({.contractId = my_contract}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_get_contract);
}

TEST(AcceptContractTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_contract = "my-contract";

  AcceptContractResponse expected_accept_contract =
      MakeResponse<AcceptContractResponse>();
  expected_accept_contract.data.contract.id = my_contract;
  httplib::Result expected_result = MakeResultOk(expected_accept_contract);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/contracts/" + my_contract + "/accept", kAuthHeaders))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<AcceptContractResponse, RequestError> result =
      session.AcceptContract(
          AcceptContractRequest({.contractId = my_contract}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_accept_contract);
}

TEST(AcceptContractTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_contract = "my-contract";

  AcceptContractResponse expected_accept_contract =
      MakeResponse<AcceptContractResponse>();
  expected_accept_contract.data.contract.id = my_contract;
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/contracts/" + my_contract + "/accept", _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<AcceptContractResponse, RequestError> result =
      session.AcceptContract(
          AcceptContractRequest({.contractId = my_contract}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(DeliverContractTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_contract = "my-contract";

  DeliverContractResponse expected_deliver_contract =
      MakeResponse<DeliverContractResponse>();
  expected_deliver_contract.data.contract.id = my_contract;
  httplib::Result expected_result = MakeResultOk(expected_deliver_contract);
  EXPECT_CALL(*mock_client, Post("/v2/my/contracts/" + my_contract + "/deliver",
                                 kAuthHeaders, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<DeliverContractResponse, RequestError> result =
      session.DeliverContract(
          DeliverContractRequest({.contractId = my_contract}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_deliver_contract);
}

TEST(DeliverContractTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_contract = "my-contract";

  DeliverContractResponse expected_deliver_contract =
      MakeResponse<DeliverContractResponse>();
  expected_deliver_contract.data.contract.id = my_contract;
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/contracts/" + my_contract + "/deliver", _, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<DeliverContractResponse, RequestError> result =
      session.DeliverContract(
          DeliverContractRequest({.contractId = my_contract}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(FulfillContractTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);
  const std::string my_contract = "my-contract";

  FulfillContractResponse expected_fulfill_contract =
      MakeResponse<FulfillContractResponse>();
  expected_fulfill_contract.data.contract.id = my_contract;
  httplib::Result expected_result = MakeResultOk(expected_fulfill_contract);
  EXPECT_CALL(*mock_client, Post("/v2/my/contracts/" + my_contract + "/fulfill",
                                 kAuthHeaders))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<FulfillContractResponse, RequestError> result =
      session.FulfillContract(
          FulfillContractRequest({.contractId = my_contract}, {}, {}));
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_fulfill_contract);
}

TEST(FulfillContractTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_contract = "my-contract";

  FulfillContractResponse expected_fulfill_contract =
      MakeResponse<FulfillContractResponse>();
  expected_fulfill_contract.data.contract.id = my_contract;
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client,
              Post("/v2/my/contracts/" + my_contract + "/fulfill", _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<FulfillContractResponse, RequestError> result =
      session.FulfillContract(
          FulfillContractRequest({.contractId = my_contract}, {}, {}));
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}