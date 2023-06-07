fn main() {
    dbg!(Solution::min_flips(1,2,3));
}

struct Solution;

// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

impl Solution {
    pub fn min_flips(a: i32, b: i32, c: i32) -> i32 {
        let mut sum = 0;
        for i in 0..32 {
            let ci = (c >> i) & 1;
            let ai = (a >> i) & 1;
            let bi = (b >> i) & 1;
            if ci == 0 {
                sum += ai + bi;
            } else {
                sum += (ai + bi == 0) as i32;
            }

            println!("{} {} => {}", ai, bi, ci);
        }
        sum
    }
}
