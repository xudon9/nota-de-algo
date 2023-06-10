
fn main() {
    let n = Solution::max_value(685453290, 293811406, 689728311);
    dbg!(n);
}

struct Solution;

// https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/

fn min_area(n: i32, height: i32) -> Option<i32> {
    let v = if n <= height {
        (2 * height - n + 1).checked_mul(n)? / 2
    } else {
        (height + 1).checked_mul(height)? / 2 + n - height
    };
    Some(v)
}

fn min_total_value(n: i32, index: i32, height: i32) -> Option<i32> {
    let left = min_area(index + 1, height)?;
    let right = min_area(n - index - 1, height - 1)?;
    Some(left.checked_add(right)?)
}

impl Solution {
    pub fn max_value(n: i32, index: i32, max_sum: i32) -> i32 {
        let mut left = 0;
        let mut right = max_sum + 1;
        while left < right {
            let mid = (left + right) / 2;
            let area = min_total_value(n, index, mid).unwrap_or(max_sum + 1);
            if area > max_sum {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left - 1;
    }
}
