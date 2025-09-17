// Last updated: 9/18/2025, 12:57:34 AM
class SnapshotArray {
private:
    vector<map<int, int>> snapArray;
    int snapCount = 0;
public:
    SnapshotArray(int length) : snapArray(length, {{0, 0}}) {
        
    }
    
    void set(int index, int val) {
        snapArray[index][snapCount] = val;
    }
    
    int snap() {
        snapCount++;
        return snapCount - 1;
    }
    
    int get(int index, int snap_id) {
        return (--snapArray[index].upper_bound(snap_id))->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */