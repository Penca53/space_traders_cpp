#pragma once

#include <chrono>
#include <mutex>

class RateLimiter {
 public:
  explicit RateLimiter() = default;
  explicit RateLimiter(uint32_t max_requests_per_second);

  void Wait();

 private:
  std::chrono::steady_clock::time_point last_;
  std::chrono::milliseconds request_delay_;
  std::mutex mutex_;
};