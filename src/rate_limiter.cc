#include "space_traders_cpp/rate_limiter.h"

#include <iostream>
#include <thread>

RateLimiter::RateLimiter(uint32_t max_requests_per_second) {
  request_delay_ = std::chrono::milliseconds(1000 / max_requests_per_second);
}

void RateLimiter::Wait() {
  std::lock_guard<std::mutex> lock(mutex_);

  const auto now = std::chrono::steady_clock::now();
  auto elapsed = now - last_;

  // Wait until the elapsed time is greater than the limit.
  if (elapsed < request_delay_) {
    std::this_thread::sleep_for(request_delay_ - elapsed);
  }

  last_ = std::chrono::steady_clock::now();
}