#pragma once

#include "space_traders_cpp/i_client.h"

class Client : public IClient {
 public:
  explicit Client(const std::string& url);
  virtual httplib::Result Get(const std::string& path,
                              const httplib::Params& params,
                              const httplib::Headers& headers) override;
  virtual httplib::Result Post(const std::string& path,
                               const httplib::Headers& headers) override;
  virtual httplib::Result Post(const std::string& path, const std::string& body,
                               const std::string& content_type) override;
  virtual httplib::Result Post(const std::string& path,
                               const httplib::Headers& headers,
                               const std::string& body,
                               const std::string& content_type) override;
  virtual httplib::Result Patch(const std::string& path,
                                const httplib::Headers& headers,
                                const std::string& body,
                                const std::string& content_type) override;

 private:
  httplib::Client client_;
};