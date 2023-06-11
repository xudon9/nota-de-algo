// https://leetcode.com/problems/find-smallest-letter-greater-than-target/
impl Solution {
    pub fn next_greatest_letter(cs: Vec<char>, c: char) -> char {
        let i = cs.partition_point(|&x| x <= c);
        let idx = if i < cs.len() {i} else {0};
        unsafe {
            *cs.get_unchecked(idx)
        }
    }
}

