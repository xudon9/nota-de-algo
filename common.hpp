#include <bits/stdc++.h>

using std::cerr;
using std::cout;
using std::endl;
using std::printf;
using std::string;
using std::vector;

template <typename T1, typename T2>
inline std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &p) {
  return os << "(" << p.first << "," << p.second << ")";
}

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
  os << "[" << v.size() << "; ";
  auto it = v.begin(), ite = v.end();
  for (; it != ite; ++it) {
    os << *it << (std::next(it) == ite ? "]" : " ");
  }
  return os;
}

template <typename V>
inline std::ostream &operator<<(std::ostream &os, const std::set<V> &m) {
  os << "{" << m.size() << "; ";
  auto it = m.begin(), ite = m.end();
  for (; it != ite; ++it) {
    os << *it << (std::next(it) == ite ? "}" : " ");
  }
  return os;
}

template <typename K, typename V>
inline std::ostream &operator<<(std::ostream &os, const std::map<K, V> &m) {
  os << "{" << m.size() << "; ";
  auto it = m.begin(), ite = m.end();
  for (; it != ite; ++it) {
    os << it->first << ":" << it->second << (std::next(it) == ite ? "}" : " ");
  }
  return os;
}

std::string escapeString(const std::string &str) {
  std::string escapedStr;
  escapedStr.reserve(str.size());
  for (char c : str) {
    switch (c) {
    case '\0':
      escapedStr += "\\0";
      break;
    case '\\':
      escapedStr += "\\\\";
      break;
    case '\"':
      escapedStr += "\\\"";
      break;
    case '\'':
      escapedStr += "\\\'";
      break;
    case '\t':
      escapedStr += "\\t";
      break;
    case '\r':
      escapedStr += "\\r";
      break;
    case '\n':
      escapedStr += "\\n";
      break;
    default:
      escapedStr += c;
      break;
    }
  }
  return escapedStr;
}

template <typename T> std::string printExprWithVal(const char *expr, T &&val) {
  std::stringstream ss;
  ss << val;
  std::string s{ss.str()};
  if (s == expr) {
    return s;
  }
  std::string s2{"\"" + escapeString(s) + "\""};
  if (s2 == expr)
    return s;
  return expr + std::string("=") + s;
}

#define EXPAND(x) x
#define GET_MACRO(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, NAME, ...) NAME
#define PASTE(...)                                                             \
  EXPAND(GET_MACRO(__VA_ARGS__ __VA_OPT__(, ) PASTE10, PASTE9, PASTE8, PASTE7, \
                   PASTE6, PASTE5, PASTE4, PASTE3, PASTE2, PASTE1,             \
                   PASTE0)(__VA_ARGS__))
#define PASTE0(func)
#define PASTE1(func, v1) func(1, v1)
#define PASTE2(func, v1, v2) func(2, v1) PASTE1(func, v2)
#define PASTE3(func, v1, v2, v3) func(3, v1) PASTE2(func, v2, v3)
#define PASTE4(func, v1, v2, v3, v4) func(4, v1) PASTE3(func, v2, v3, v4)
#define PASTE5(func, v1, ...) func(5, v1) PASTE4(func, __VA_ARGS__)
#define PASTE6(func, v1, ...) func(6, v1) PASTE5(func, __VA_ARGS__)
#define PASTE7(func, v1, ...) func(7, v1) PASTE6(func, __VA_ARGS__)
#define PASTE8(func, v1, ...) func(8, v1) PASTE7(func, __VA_ARGS__)
#define PASTE9(func, v1, ...) func(9, v1) PASTE8(func, __VA_ARGS__)
#define PASTE10(func, v1, ...) func(10, v1) PASTE9(func, __VA_ARGS__)
// Add more if you need more than 10 parameters
#define ACTION_DECL(i, expr) const auto &_tmp##i{expr};
#define ACTION_PRINT(i, x)                                                     \
  {                                                                            \
    auto str = printExprWithVal(#x, _tmp##i);                                  \
    if (!str.empty()) {                                                        \
      std::cerr << "\033[36m" << str[0] << "\033[0m" << str.c_str() + 1;       \
    }                                                                          \
    std::cerr << (i == 1 ? "\n" : "  ");                                       \
  }

#define DEBUG(...)                                                             \
  do {                                                                         \
    EXPAND(PASTE(ACTION_DECL __VA_OPT__(, ) __VA_ARGS__))                      \
    std::cerr << "\033[34mDBG\033[0m " << __FILE__ << ":" << __LINE__ << ": "; \
    EXPAND(PASTE(ACTION_PRINT __VA_OPT__(, ) __VA_ARGS__))                     \
  } while (0)

#define TEST(lhs, rhs)                                                         \
  do {                                                                         \
    auto _v_lhs = (lhs);                                                       \
    auto _v_rhs = (rhs);                                                       \
    bool equal = _v_lhs == _v_rhs;                                             \
    std::cerr << (equal ? "\033[32mPASS\033[0m" : "\033[31mFAIL\033[0m")       \
              << " " << printExprWithVal(#lhs, _v_lhs)                         \
              << (equal ? " == " : " != ") << printExprWithVal(#rhs, _v_rhs)   \
              << std::endl;                                                    \
  } while (0)
