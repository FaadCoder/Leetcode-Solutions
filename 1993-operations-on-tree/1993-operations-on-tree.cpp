class LockingTree {
public:
    LockingTree(vector<int>& p) : parent(p) {
        for (int i = 0; i < parent.size(); i++) 
            children[parent[i]].push_back(i);
    }
    
    bool lock(int num, int user) {
        if (locked_by.find(num) != locked_by.end()) return false;
        locked_by[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if (locked_by.find(num) == locked_by.end()) return false;
        if (locked_by[num] != user) return false;
        locked_by.erase(num);
        return true;
    }
    
    bool is_locked_child(int num) {
        bool flag = false;
        if (locked_by.find(num) != locked_by.end()) flag = true;
        for (auto ch : children[num]) flag |= is_locked_child(ch);
        return flag;
    }
    
    bool is_locked_parent(int num) {
        if (num == -1) return false;
        if (locked_by.find(num) != locked_by.end()) return true;
        return is_locked_parent(parent[num]);
    }
    
    void unlock_descendants(int num) {
        for (auto ch : children[num]) {
            locked_by.erase(ch);
            unlock_descendants(ch);
        }
    }
    
    bool upgrade(int num, int user) {
        if (locked_by.find(num) != locked_by.end()) return false;
        if (is_locked_child(num) && !is_locked_parent(parent[num])) {
            unlock_descendants(num);
            locked_by[num] = user;
            return true;
        }
        return false;
    }
    
private:
    unordered_map<int, vector<int> > children;
    unordered_map<int, int> locked_by;
    vector<int> parent;
};