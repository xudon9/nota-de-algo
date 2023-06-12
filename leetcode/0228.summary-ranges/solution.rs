fn main() {
    dbg!(Solution::summary_ranges(vec![]));
    dbg!(Solution::summary_ranges(vec![0]));
    dbg!(Solution::summary_ranges(vec![2, 3]));
    dbg!(Solution::summary_ranges(vec![0, 1, 2, 4, 5, 7]));
    dbg!(Solution::summary_ranges(vec![0, 2, 3, 4, 6, 8, 9]));
}

struct Solution;
// https://leetcode.com/problems/summary-ranges/

fn create_range(i: i32, j: i32) -> String {
    if i == j {
        i.to_string()
    } else {
        format!("{}->{}", i, j)
    }
}

impl Solution {
    pub fn summary_ranges(nums: Vec<i32>) -> Vec<String> {
        let mut it = nums.into_iter();
        if let Some(mut fst) = it.next() {
            let mut snd = fst;
            let mut ret = vec![];
            while let Some(n) = it.next() {
                if n == snd + 1 {
                    snd = n;
                } else {
                    ret.push(create_range(fst, snd));
                    fst = n;
                    snd = n;
                }
            }
            ret.push(create_range(fst, snd));
            ret
        } else {
            vec![]
        }
    }
}
