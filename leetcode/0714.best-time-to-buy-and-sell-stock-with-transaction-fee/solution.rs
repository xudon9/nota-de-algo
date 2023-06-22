fn main() {
    let n = Solution::max_profit(vec![1, 3, 2, 8, 4, 9], 2);
    println!("{}", n);
}

struct Solution;
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
impl Solution {
    pub fn max_profit(prices: Vec<i32>, fee: i32) -> i32 {
        let mut i = prices.into_iter();
        let n = i.next().unwrap_or_default();
        i.fold((0, -n), |(x, y), p| (x.max(y + p - fee), y.max(x - p))).0
    }
}
