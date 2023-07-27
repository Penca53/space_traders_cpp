#pragma once

#include "httplib.h"

class IClient {
 public:
  virtual ~IClient() {}
  virtual httplib::Result Get(const std::string& path,
                              const httplib::Params& params,
                              const httplib::Headers& headers) = 0;
  virtual httplib::Result Post(const std::string& path,
                               const httplib::Headers& headers) = 0;
  virtual httplib::Result Post(const std::string& path, const std::string& body,
                               const std::string& content_type) = 0;
  virtual httplib::Result Post(const std::string& path,
                               const httplib::Headers& headers,
                               const std::string& body,
                               const std::string& content_type) = 0;
  virtual httplib::Result Patch(const std::string& path,
                                const httplib::Headers& headers,
                                const std::string& body,
                                const std::string& content_type) = 0;
};