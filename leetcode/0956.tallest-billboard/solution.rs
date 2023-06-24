fn main() {
    let v = vec![1, 2, 3, 4, 5, 6];
    dbg!(Solution::tallest_billboard(v));
}

struct Solution;
// https://leetcode.com/problems/minimum-cost-to-make-array-equal/

fn update(oldh: &mut u16, newh: u16) {
    *oldh = (*oldh).max(1 | newh << 1);
}

impl Solution {
    pub fn tallest_billboard(rods: Vec<i32>) -> i32 {
        let n_elem = rods.iter().sum::<i32>() as usize + 1;
        let mut dp = [0u16; 5001];
        let mut old = [0u16; 5001];
        dp[0] = 1;
        for n in rods {
            old[0..n_elem].copy_from_slice(&dp[0..n_elem]);
            for (d, h) in (0..n_elem)
                .filter_map(|d| (old[d] != 0).then(|| (d, old[d] >> 1)))
            {
                update(&mut dp[d + n as usize], h + n as u16);
                let newd = n - d as i32;
                if newd < 0 {
                    update(&mut dp[(-newd) as usize], h);
                } else {
                    update(&mut dp[newd as usize], h + newd as u16);
                }
            }
        }
        (dp[0] >> 1) as i32
    }
}
