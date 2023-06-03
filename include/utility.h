#pragma once

#include "json.h"

#include <optional>
#include <variant>

template <typename T>
struct Ok {
  explicit Ok(T val) : val(val) {}
  T val;
};

template <typename E>
struct Err {
  explicit Err(E val) : val(val) {}
  E val;
};

template <typename T, typename E>
struct Result {
 public:
  Result(Ok<T> ok) { value_ = ok.val; }
  Result(Err<E> err) { value_ = err.val; }

  bool IsOk() { return value_.index() == 0; }
  bool IsErr() { return value_.index() == 1; }
  T Ok() { return std::get<0>(value_); }
  E Err() { return std::get<1>(value_); }

 private:
  std::variant<T, E> value_;
};

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
