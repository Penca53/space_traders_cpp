#pragma once

#include <optional>
#include <variant>

#include "nlohmann/json.hpp"

template <typename T>
struct Ok {
  explicit Ok(const T& val) : val(val) {}
  T val;
};

template <typename E>
struct Err {
  explicit Err(const E& val) : val(val) {}
  E val;
};

template <typename T, typename E>
struct Result {
 public:
  Result(const Ok<T>& ok) { value_ = ok.val; }
  Result(const Err<E>& err) { value_ = err.val; }

  bool IsOk() const { return value_.index() == 0; }
  bool IsErr() const { return value_.index() == 1; }
  T Ok() const { return std::get<0>(value_); }
  E Err() const { return std::get<1>(value_); }

 private:
  std::variant<T, E> value_;
};

static constexpr int32_t kHttpOkStatus = 200;
static constexpr int32_t kHttpCreatedStatus = 201;
static constexpr int32_t kHttpNoContentStatus = 204;

static constexpr int32_t kHttpUnauthorizedStatus = 401;
static constexpr int32_t kHttpUnprocessableEntityStatus = 422;

NLOHMANN_JSON_NAMESPACE_BEGIN
template <typename T>
struct adl_serializer<std::optional<T>> {
  static void to_json(json& j, const std::optional<T>& opt) {
    if (opt == std::nullopt) {
      j = nullptr;
    } else {
      j = opt.value();  // this will call adl_serializer<T>::to_json which will
                        // find the free function to_json in T's namespace!
    }
  }

  static void from_json(const json& j, std::optional<T>& opt) {
    if (j.is_null()) {
      opt = std::nullopt;
    } else {
      opt = j.get<T>();  // same as above, but with
                         // adl_serializer<T>::from_json
    }
  }
};
NLOHMANN_JSON_NAMESPACE_END
