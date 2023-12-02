// This is free and unencumbered software released into the public domain.
// 
// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software, either in source code form or as a compiled
// binary, for any purpose, commercial or non-commercial, and by any
// means.
// 
// In jurisdictions that recognize copyright laws, the author or authors
// of this software dedicate any and all copyright interest in the
// software to the public domain. We make this dedication for the benefit
// of the public at large and to the detriment of our heirs and
// successors. We intend this dedication to be an overt act of
// relinquishment in perpetuity of all present and future rights to this
// software under copyright law.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
// 
// For more information, please refer to <https://unlicense.org>

#ifndef ADVANCED_ENUM_ENUM_ENUM_H_
#define ADVANCED_ENUM_ENUM_ENUM_H_

#include "macro-hell.inc"

#include <compare>
#include <format>

#ifndef ENUM_ENCRYPTION_STRING
#define ENUM_ENCRYPTION_STRING(x) x
#endif

#define ENUM_DEFINE_ENUM_EXPAND(enum_member_name) enum_member_name,

#define ENUM_DEFINE_ENUM_IS(enum_member_name)     \
[[nodiscard]] bool Is##enum_member_name() const { \
  return value_ == (enum_member_name);            \
} 

#define ENUM_DEFINE_ENUM_CASE(enum_member_name)     \
case enum_member_name: {                            \
  return ENUM_ENCRYPTION_STRING(#enum_member_name); \
}

#define DEFINE_ENUM(enum_name, ...)                               \
class enum_name {                                                 \
 public:                                                          \
  enum {                                                          \
    ENUM_EXPAND(ENUM_PASTE(ENUM_DEFINE_ENUM_EXPAND, __VA_ARGS__)) \
  };                                                              \
 private:                                                         \
  using EnumType = decltype(VA_ARG_FIRST(__VA_ARGS__));           \
 public:                                                          \
  enum_name() : value_(VA_ARG_FIRST(__VA_ARGS__)) {}              \
  enum_name(const EnumType &value) : value_(value) {}             \
  constexpr auto operator<=>(const enum_name &) const = default;  \
  enum_name &operator=(const EnumType &value) {                   \
	  value_ = value;                                         \
	  return *this;                                           \
  }                                                               \
  ENUM_EXPAND(ENUM_PASTE(ENUM_DEFINE_ENUM_IS, __VA_ARGS__))       \
  [[nodiscard]] std::string ToString() const {                    \
    switch (value_) {                                             \
      ENUM_EXPAND(ENUM_PASTE(ENUM_DEFINE_ENUM_CASE, __VA_ARGS__)) \
    }                                                             \
    return ENUM_ENCRYPTION_STRING("Err");                         \
  }                                                               \
 private:                                                         \
  EnumType value_;                                                \
};                                                                \

#define DEFINE_ENUM_WITH_FORMATTER(enum_name, ...)                \
DEFINE_ENUM(enum_name, __VA_ARGS__)				  \
                                                                  \
template <>                                                       \
struct std::formatter<enum_name> : std::formatter<std::string> {  \
  auto format(const enum_name e, format_context& ctx) const {     \
    return formatter<string>::format(                             \
			std::format("{}", e.ToString()), ctx);    \
  }                                                               \
}

#endif //ADVANCED_ENUM_ENUM_ENUM_H_
