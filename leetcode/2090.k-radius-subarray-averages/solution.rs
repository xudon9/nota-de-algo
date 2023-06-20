struct Solution;
// https://leetcode.com/problems/k-radius-subarray-averages
impl Solution {
    pub fn get_averages(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let len = nums.len();
        if k == 0 {
            nums
        } else if len as i32 <= 2 * k {
            vec![-1; len]
        } else {
            let mut result = Vec::with_capacity(nums.len());
            let mut sum = 0u64;
            let n = (2 * k + 1) as u64;
            let mut it = nums.iter();
            for _ in 0..k {
                result.push(-1)
            }
            for _ in 0..2 * k {
                sum += (*it.next().unwrap()) as u64;
            }
            for (&x, &y) in nums.iter().zip(it) {
                sum += y as u64;
                result.push((sum / n) as i32);
                sum -= x as u64;
            }
            for _ in 0..k {
                result.push(-1)
            }
            result
        }
    }
}
