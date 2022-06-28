class SnapshotArray {
    int snapCount = 0;
    unordered_map<int,map<int,int>> snapToIdxToElementMap;
public:
    SnapshotArray(int length) {
        for (int i = 0; i < length; i++) {
            map<int, int> mp; mp[0] = 0;
            snapToIdxToElementMap[i] = mp;
        }
    }
    
    void set(int index, int val) {
        snapToIdxToElementMap[index][snapCount] = val;
    }
    
    int snap() {
       return snapCount++;
    }
    
    int get(int index, int snap_id) {
        auto it = snapToIdxToElementMap[index].upper_bound(snap_id); 
        if(it==snapToIdxToElementMap[index].begin())
            return 0;
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