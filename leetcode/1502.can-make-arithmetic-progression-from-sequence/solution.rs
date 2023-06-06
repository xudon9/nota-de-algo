// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/description/

impl Solution {
    pub fn can_make_arithmetic_progression(mut arr: Vec<i32>) -> bool {
        arr.sort();
        let mut it = arr.iter();
        let v0 = it.next().unwrap();
        let mut last = it.next().unwrap();
        let diff = last - v0;
        while let Some(v) = it.next() {
            if v - last != diff {
                return false;
            }
            last = v;
        }
        true
    }
}
