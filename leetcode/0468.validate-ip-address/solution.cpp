#include <string>
// https://leetcode.com/problems/validate-ip-address/

#define ISDEC(c) ('0' <= (c) && (c) <= '9')
#define ISHEX(c)                                                               \
  (ISDEC(c) || 'a' <= (c) && (c) <= 'f' || 'A' <= (c) && (c) <= 'F')

bool isIPv4(const char *p) {
#define A(action)                                                              \
  if (ISDEC(*d)) {                                                             \
    value = value * 10 + *d++ - '0';                                           \
    action                                                                     \
  }
  int n_seen = 0;
  for (;;) {
    unsigned value = 0;
    const char *d = p;
    A(A(A({}))); // Skip at most 3 digits
    if (d == p || (d - p > 1 && *p == '0') || value > 0xff)
      // No number,leading zero, large value
      return 0;
    ++n_seen;
    if (n_seen == 4)
      return !*d;
    if (*d == '.')
      p = d + 1;
    else
      return false;
  }
#undef A
}

bool isIPv6(const char *p) {
#define A(action)                                                              \
  if (ISHEX(*d)) {                                                             \
    d++;                                                                       \
    action                                                                     \
  }
  int n_seen = 0;
  for (;;) {
    const char *d = p;
    A(A(A(A({})))); // Skip at most 4 digits
    if (d == p)
      // No number
      return 0;
    ++n_seen;
    if (n_seen == 8)
      return !*d;
    if (*d == ':')
      p = d + 1;
    else
      return false;
  }
#undef A
}

class Solution {
public:
  static std::string validIPAddress(const std::string &s) {
    if (isIPv4(s.c_str()))
      return "IPv4";
    if (isIPv6(s.c_str()))
      return "IPv6";
    return "Neither";
  }
};
