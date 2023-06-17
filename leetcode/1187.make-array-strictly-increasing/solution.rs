fn main() {
    let v1 = vec![1, 5, 3, 6, 7];

    // let v2 = vec![1, 3, 2, 4];
    // let v2 = vec![4,3,1];
    let v2 = vec![1, 6, 3, 3];

    dbg!(Solution::make_array_increasing(v1, v2));
}

struct Solution;
// https://leetcode.com/problems/make-array-strictly-increasing
use std::cmp;

impl Solution {
    pub fn make_array_increasing(arr1: Vec<i32>, mut arr2: Vec<i32>) -> i32 {
        arr2.sort();
        let mut prev = vec![(0i32, -1)];
        for now_val in arr1.into_iter() {
            let mut curr = vec![];
            for (last_mod, last_val) in prev.into_iter() {
                if last_val < now_val {
                    match curr.last_mut() {
                        Some((n, v)) if *n == last_mod => {
                            *v = cmp::min(*v, now_val)
                        }
                        _ => curr.push((last_mod, now_val)),
                    }
                }
                let index = arr2.partition_point(|&v| v <= last_val);
                if let Some(&v) = arr2.get(index) {
                    // This line is optional
                    if curr.last().filter(|p| p.1 <= v).is_none() {
                        curr.push((last_mod + 1, v));
                    }
                }
            }
            prev = curr;
        }
        prev.into_iter().next().map_or(-1, |(c, _)| c)
    }
}
