#include <stdbool.h>
#include <stdio.h>
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

char *validIPAddress(const char *s) {
  if (s) {
    if (isIPv4(s))
      return "IPv4";
    if (isIPv6(s))
      return "IPv6";
  }
  return "Neither";
}

int main() {
  const char *tests[] = {"192.168.1.1",
                         "192.168.1.0",
                         "192.168.1.0    ",
                         "192.168.01.1",
                         "192.168.1.00",
                         "192.168@1.1",
                         "2001:0db8:85a3:0000:0000:8a2e:0370:7334",
                         "2001:db8:85a3:0:0:8A2E:0370:7334",
                         "2001:0db8:85a3::8A2E:037j:7334",
                         "02001:0db8:85a3:0000:0000:8a2e:0370:7334"};
  const int n = sizeof(tests) / sizeof(tests[0]);
  for (int i = 0; i < n; ++i) {
    const char *s = tests[i];
    printf("%s\t<- \"%s\"\n", validIPAddress(s), s);
  }
}
