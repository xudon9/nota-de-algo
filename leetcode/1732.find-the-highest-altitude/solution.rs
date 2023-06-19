struct Solution;
// https://leetcode.com/problems/find-the-highest-altitude/

impl Solution {
    pub fn largest_altitude(gain: Vec<i32>) -> i32 {
        gain.into_iter()
            .fold((0, 0), |(x, m), d| {
                let y = x + d;
                (y, m.max(y))
            })
            .1
    }
}
