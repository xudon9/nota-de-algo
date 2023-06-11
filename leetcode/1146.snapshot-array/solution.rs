fn main() {
    let mut a = SnapshotArray::new(3);
    a.set(0, 5);
    dbg!(a.snap());
    a.set(0, 6);
    dbg!(a.get(0, 0));
}

/* https://leetcode.com/problems/snapshot-array/ */

#[derive(Debug)]
struct SnapshotArray {
    version: i32,
    content: Vec<Vec<(i32, i32)>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl SnapshotArray {
    fn new(length: i32) -> Self {
        SnapshotArray {
            version: 0,
            content: vec![vec![]; length as usize],
        }
    }

    fn set(&mut self, index: i32, val: i32) {
        unsafe {
            let ci = self.content.get_unchecked_mut(index as usize);
            match ci.last_mut() {
                Some((i, v)) if *i == self.version => *v = val,
                _ => ci.push((self.version, val)),
            }
        }
    }

    fn snap(&mut self) -> i32 {
        let v = self.version;
        self.version += 1;
        v
    }

    fn get(&self, index: i32, snap_id: i32) -> i32 {
        unsafe {
            let ci = self.content.get_unchecked(index as usize);
            let idx = ci.partition_point(|p| p.0 <= snap_id);
            if idx == 0 {
                0
            } else {
                ci.get_unchecked(idx - 1).1
            }
        }
    }
}

/*
 * Your SnapshotArray object will be instantiated and called as such:
 * let obj = SnapshotArray::new(length);
 * obj.set(index, val);
 * let ret_2: i32 = obj.snap();
 * let ret_3: i32 = obj.get(index, snap_id);
 */

