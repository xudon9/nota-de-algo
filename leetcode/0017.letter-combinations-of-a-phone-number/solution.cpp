#include "../../common.hpp"
// auto fastio {[](){ std::ios::sync_with_stdio(0); std::cin.tie(0); return
// nullptr; }()};
//  https://leetcode.com/problems/letter-combinations-of-a-phone-number

vector<string> kbd = {
    "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
};

class Solution {
public:
  static vector<string> letterCombinations(string digits) {
    vector<string> result = {""};
    if (digits.length() == 0)
      return vector<string>();
    for (char d : digits) {
      vector<string> new_results = {};
      const string &values = kbd[d - '2'];
      for (string &prefix : result) {
        for (char suffix : values) {
          new_results.push_back(prefix + suffix);
        }
      }
      std::swap(result, new_results);
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
