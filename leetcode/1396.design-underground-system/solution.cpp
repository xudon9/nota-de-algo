#include "../../common.hpp"
using namespace std;

class UndergroundSystem {
  using K = pair<string, string>;
  using NT = pair<unsigned, double>;
  using ST = pair<string, int>;

  map<K, NT> log;
  map<int, ST> ppl;

public:
  UndergroundSystem() {}

  void checkIn(int id, string stationName, int t) {
    ppl.emplace(id, make_pair(stationName, t));
  }

  void checkOut(int id, string stationName, int t) {
    auto it = ppl.find(id);
    assert(it != ppl.end());
    auto [inStation, inTime] = it->second;
    NT& nt = log[make_pair(inStation, stationName)];
    ++nt.first;
    nt.second += (t - inTime);
    ppl.erase(it);
  }

  double getAverageTime(string s0, string s1) {
    auto it = log.find(make_pair(s0, s1));
    if (it == log.end())
      return 0;
    auto [n, t] = it->second;
    return t / n;
  }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
int main()
{
}

