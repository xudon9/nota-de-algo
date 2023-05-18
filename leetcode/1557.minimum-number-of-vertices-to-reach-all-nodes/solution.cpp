// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes
#include "../../common.hpp"

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges) {
        std::vector<bool> hasIncom(n, false);
        std::vector<int> result;
        result.reserve(n);

        for (auto &pair : edges) {
          hasIncom[pair[1]] = true;
        }

        for (int i = 0; i < n; ++i) {
          if (!hasIncom[i])
            result.emplace_back(i);
        }
        return result;
    }
};
