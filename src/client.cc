#include "space_traders_cpp/client.h"

Client::Client(const std::string& url) : client_(url) {}
httplib::Result Client::Get(const std::string& path,
                            const httplib::Params& params,
                            const httplib::Headers& headers) {
  return client_.Get(path, params, headers);
}
httplib::Result Client::Post(const std::string& path,
                             const httplib::Headers& headers) {
  return client_.Post(path, headers);
}

httplib::Result Client::Post(const std::string& path, const std::string& body,
                             const std::string& content_type) {
  return client_.Post(path, body, content_type);
}
httplib::Result Client::Post(const std::string& path,
                             const httplib::Headers& headers,
                             const std::string& body,
                             const std::string& content_type) {
  return client_.Post(path, headers, body, content_type);
}
httplib::Result Client::Patch(const std::string& path,
                              const httplib::Headers& headers,
                              const std::string& body,
                              const std::string& content_type) {
  return client_.Patch(path, headers, body, content_type);
}
