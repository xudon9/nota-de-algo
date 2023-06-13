fn main() {}

struct Solution;
// https://leetcode.com/problems/equal-row-and-column-pairs/
use std::collections::HashMap;

impl Solution {
    pub fn equal_pairs(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let transposed: Vec<Vec<i32>> = (0..n)
            .map(|col| (0..n).map(|row| grid[row][col]).collect())
            .collect();

        let mut row_map: HashMap<Vec<i32>, i32> = HashMap::new();
        for row in grid {
            *row_map.entry(row).or_default() += 1;
        }
        transposed
            .iter()
            .map(|c| row_map.get(c).cloned().unwrap_or_default())
            .sum()
    }
}
