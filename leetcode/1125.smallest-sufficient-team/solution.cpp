#include "../../common.hpp"
#include <numeric>
// auto fastio {[](){ std::ios::sync_with_stdio(0); std::cin.tie(0); return
// nullptr; }()};
//  https://leetcode.com/problems/smallest-sufficient-team/

#define PAR // std::execution::par,
#define MAX_PEOPLE 60

struct Solution {
    using BS = uint16_t;
    struct PplInfo {
        BS peopleCount;
        BS peopleIndex;
        BS restColIndex;
    };

    static vector<int> debug(const vector<string> &req_skills,
                             const vector<vector<string>> &people) {
        auto r = req_skills;
        return smallestSufficientTeam(r, people);
    }

    static BS go(PplInfo *dp, BS *ppl, BS ppl_len, BS set) {
        if (set == 0)
            return 0;
        auto &info{dp[set]};
        BS cnt = info.peopleCount;
        if (cnt)
            return cnt;
        BS min_ppl_cnt = MAX_PEOPLE, min_ppl_idx, min_ppl_set;
        for (int i = 0; i < ppl_len; ++i) {
            BS rest = set & ~ppl[i];
            if (rest == set)
                continue;
            BS ppl_cnt = 1 + go(dp, ppl, ppl_len, rest);
            if (ppl_cnt < min_ppl_cnt) {
                min_ppl_cnt = ppl_cnt;
                min_ppl_idx = i;
                min_ppl_set = rest;
            }
        }
        info = {min_ppl_cnt, min_ppl_idx, min_ppl_set};
        return min_ppl_cnt;
    }

    static vector<int>
    smallestSufficientTeam(vector<string> &req_skills,
                           const vector<vector<string>> &people) {
        BS ppl_len = people.size(), ppl[60],
           full = (1 << req_skills.size()) - 1;
        {
            std::map<string, BS> map;
            for (BS i = 0, n = req_skills.size(); i < n; ++i) {
                map.emplace(std::move(req_skills[i]), i);
            }
            std::transform(PAR people.begin(), people.end(), ppl,
                           [&](const vector<string> &p) {
                               return std::transform_reduce(
                                   PAR p.begin(), p.end(), (BS)0, std::bit_or(),
                                   [&](const std::string &skill) {
                                       return (BS)1 << map[skill];
                                   });
                           });
        }

        PplInfo dp[full + 1];
        memset(dp, 0, sizeof(dp));
        go(dp, ppl, ppl_len, full);

        std::vector<int> result;
        result.reserve(MAX_PEOPLE);
        PplInfo *link = dp + full;
        while (link->peopleCount) {
            result.push_back(link->peopleIndex);
            link = dp + link->restColIndex;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution s;

    TEST((vector<int>{0, 2}),
         s.debug({"java", "nodejs", "reactjs"},
                 {{"java"}, {"nodejs"}, {"nodejs", "reactjs"}}));
    TEST((vector<int>{1, 2}),
         s.debug({"algorithms", "math", "java", "reactjs", "csharp", "aws"},
                 {{"algorithms", "math", "java"},
                  {"algorithms", "math", "reactjs"},
                  {"java", "csharp", "aws"},
                  {"reactjs", "csharp"},
                  {"csharp", "math"},
                  {"aws", "java"}}));

    return 0;
}
