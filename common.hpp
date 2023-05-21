#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <utility>
#include <stack>
#include <queue>

using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
using std::list;
using std::map;
using std::pair;
using std::stack;
using std::queue;

#define EXPAND(x) x
#define GET_MACRO(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, NAME, ...) NAME
#define PASTE(...) \
    EXPAND(GET_MACRO(__VA_ARGS__ __VA_OPT__(, ) PASTE10, PASTE9, PASTE8, PASTE7, PASTE6, PASTE5, PASTE4, PASTE3, PASTE2, PASTE1, PASTE0)(__VA_ARGS__))
#define PASTE0(func)
#define PASTE1(func, v1) func(v1)
#define PASTE2(func, v1, v2) PASTE1(func, v1) PASTE1(func, v2)
#define PASTE3(func, v1, v2, v3) PASTE1(func, v1) PASTE2(func, v2, v3)
#define PASTE4(func, v1, v2, v3, v4) PASTE1(func, v1) PASTE3(func, v2, v3, v4)
#define PASTE5(func, v1, ...) PASTE1(func, v1) PASTE4(func, __VA_ARGS__)
#define PASTE6(func, v1, ...) PASTE1(func, v1) PASTE5(func, __VA_ARGS__)
#define PASTE7(func, v1, ...) PASTE1(func, v1) PASTE6(func, __VA_ARGS__)
#define PASTE8(func, v1, ...) PASTE1(func, v1) PASTE7(func, __VA_ARGS__)
#define PASTE9(func, v1, ...) PASTE1(func, v1) PASTE8(func, __VA_ARGS__)
#define PASTE10(func, v1, ...) PASTE1(func, v1) PASTE9(func, __VA_ARGS__)
// Add more if you need more than 8 parameters
#define ACTION(x)                            \
    {                                        \
        std::cerr << #x << "=" << x << ", "; \
    }

#define DEBUG(...)                                                      \
    do                                                                  \
    {                                                                   \
        std::cerr << "[DEBUG] " << __FILE__ << ":" << __LINE__ << ": "; \
        EXPAND(PASTE(ACTION __VA_OPT__(, ) __VA_ARGS__))                \
        std::cerr << "\b\b  \n";                                        \
    } while (0)

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    os << "vector[";
    for (auto &i : v)
    {
        os << i << ", ";
    }
    os << "\b\b]";
    return os;
}

template <typename K, typename V>
inline std::ostream &operator<<(std::ostream &os, const std::map<K, V> &m)
{
    os << "map[";
    for (auto &p : m)
    {
        os << p.first << ": " << p.second  << ", ";
    }
    os << "\b\b]";
    return os;
}
