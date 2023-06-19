#include "space_traders_cpp_test/api_test.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "nlohmann/json.hpp"
#include "space_traders_cpp/mock_client.h"
#include "space_traders_cpp/models/agent.h"
#include "space_traders_cpp/session.h"
#include "space_traders_cpp/utility.h"

using ::testing::_;
using ::testing::AtLeast;
using ::testing::ByRef;
using ::testing::Eq;
using ::testing::Return;

const static std::string kToken = "my-token";

const static httplib::Headers kAuthHeaders =
    httplib::Headers{{"Authorization", "Bearer " + kToken}};

TEST(StatusTest, ShouldReturnOkWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);

  const StatusResponse expected_status = MakeResponse<StatusResponse>();
  httplib::Result expected_result = MakeResultOk(expected_status);
  EXPECT_CALL(*mock_client, Get(_, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<StatusResponse, RequestError> result =
      session.Status(StatusRequest{});
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_status);
}

TEST(RegisterTest, ShouldReturnOkWhenSymbolNotInUse) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_symbol = "my-symbol";
  const std::string faction_symbol = "COSMIC";

  RegisterResponse expected_register = MakeResponse<RegisterResponse>();
  expected_register.data.faction.symbol = faction_symbol;
  expected_register.data.agent.symbol = my_symbol;
  httplib::Result expected_result = MakeResultOk(expected_register);
  EXPECT_CALL(*mock_client, Post(_, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<RegisterResponse, RequestError> result =
      session.Register(RegisterRequest{});
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_register);
}

TEST(RegisterTest, ShouldReturnErrWhenSymbolAlreadyInUse) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);
  const std::string my_symbol = "my-symbol";
  const std::string faction_symbol = "COSMIC";

  RegisterResponse expected_register = MakeResponse<RegisterResponse>();
  expected_register.data.faction.symbol = faction_symbol;
  expected_register.data.agent.symbol = my_symbol;
  httplib::Result expected_result =
      MakeResultErr(kHttpUnprocessableEntityStatus);
  EXPECT_CALL(*mock_client, Post(_, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<RegisterResponse, RequestError> result =
      session.Register(RegisterRequest{});
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnprocessableEntityStatus);
}

TEST(MyAgentTest, ShouldReturnOkWhenAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client, kToken);

  const MyAgentResponse expected_my_agent = MakeResponse<MyAgentResponse>();
  httplib::Result expected_result = MakeResultOk(expected_my_agent);
  EXPECT_CALL(*mock_client, Get(_, _, Eq(kAuthHeaders)))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<MyAgentResponse, RequestError> result =
      session.MyAgent(MyAgentRequest{});
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_my_agent);
}

TEST(MyAgentTest, ShouldReturnErrWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);

  const MyAgentResponse expected_my_agent = MakeResponse<MyAgentResponse>();
  httplib::Result expected_result = MakeResultErr(kHttpUnauthorizedStatus);
  EXPECT_CALL(*mock_client, Get(_, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<MyAgentResponse, RequestError> result =
      session.MyAgent(MyAgentRequest{});
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(ListContracts, ShouldReturnOkWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);

  const ListContractsResponse expected_list_contracts =
      MakeResponse<ListContractsResponse>();
  httplib::Result expected_result = MakeResultOk(expected_list_contracts);
  EXPECT_CALL(*mock_client, Get(_, _, _))
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

  const GetContractResponse expected_get_contract =
      MakeResponse<GetContractResponse>();
  httplib::Result expected_result = MakeResultOk(expected_get_contract);
  EXPECT_CALL(*mock_client, Get(_, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<GetContractResponse, RequestError> result =
      session.GetContract(GetContractRequest{});
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
  EXPECT_CALL(*mock_client, Post(_, Eq(kAuthHeaders)))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<AcceptContractResponse, RequestError> result =
      session.AcceptContract(AcceptContractRequest{});
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
  EXPECT_CALL(*mock_client, Post(_, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<AcceptContractResponse, RequestError> result =
      session.AcceptContract(AcceptContractRequest{});
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
  EXPECT_CALL(*mock_client, Post(_, Eq(kAuthHeaders), _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<DeliverContractResponse, RequestError> result =
      session.DeliverContract(DeliverContractRequest{});
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
  EXPECT_CALL(*mock_client, Post(_, _, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<DeliverContractResponse, RequestError> result =
      session.DeliverContract(DeliverContractRequest{});
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
  EXPECT_CALL(*mock_client, Post(_, Eq(kAuthHeaders)))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<FulfillContractResponse, RequestError> result =
      session.FulfillContract(FulfillContractRequest{});
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
  EXPECT_CALL(*mock_client, Post(_, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<FulfillContractResponse, RequestError> result =
      session.FulfillContract(FulfillContractRequest{});
  ASSERT_TRUE(result.IsErr());
  EXPECT_EQ(result.Err().http_status, kHttpUnauthorizedStatus);
}

TEST(ListFactionsTest, ShouldReturnOkWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);

  const ListFactionsResponse expected_list_factions =
      MakeResponse<ListFactionsResponse>();
  httplib::Result expected_result = MakeResultOk(expected_list_factions);
  EXPECT_CALL(*mock_client, Get(_, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<ListFactionsResponse, RequestError> result =
      session.ListFactions(ListFactionsRequest{});
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_list_factions);
}

TEST(GetFactionTest, ShouldReturnOkWhenNotAuthenticated) {
  const auto mock_client = std::make_shared<MockClient>();
  const Session session(mock_client);

  const GetFactionResponse expected_get_faction =
      MakeResponse<GetFactionResponse>();
  httplib::Result expected_result = MakeResultOk(expected_get_faction);
  EXPECT_CALL(*mock_client, Get(_, _, _))
      .Times(AtLeast(1))
      .WillOnce(Return(std::move(expected_result)));

  const Result<GetFactionResponse, RequestError> result =
      session.GetFaction(GetFactionRequest{});
  ASSERT_TRUE(result.IsOk());
  EXPECT_EQ(result.Ok(), expected_get_faction);
}