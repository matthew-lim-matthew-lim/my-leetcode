// Last updated: 7/10/2025, 4:00:43 PM
class SnapshotArray {
private:
    // index: index, key: snap_id, value: val
    vector<map<int, int>> vec;
    int snapId = 0;
public:
    SnapshotArray(int length) {
        vec = vector<map<int, int>>(length, map<int, int>({{0, 0}}));
    }
    
    void set(int index, int val) {
        vec[index][snapId] = val;
    }
    
    int snap() {
        snapId++;
        return snapId - 1;
    }
    
    int get(int index, int snap_id) {
        auto it = vec[index].upper_bound(snap_id);
        it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */