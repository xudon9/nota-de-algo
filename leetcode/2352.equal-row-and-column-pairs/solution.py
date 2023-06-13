#!python3
# https://leetcode.com/problems/equal-row-and-column-pairs/submissions/755015576/
from typing import List
from collections import defaultdict

class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        s = defaultdict(lambda: [0, 0])
        n = len(grid)

        for row in grid:
            s[tuple(row)][0] += 1
        for i in range(n):
            col = tuple(row[i] for row in grid)
            s[col][1] += 1

        n = 0
        for _, (r, c) in s.items():
            n += r * c
        return n
