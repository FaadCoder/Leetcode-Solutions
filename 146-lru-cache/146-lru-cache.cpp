class LRUCache {
public:
    int cap = 0;
    list<pair<int,int>> cache;
    unordered_map<int, list<pair<int,int>> :: iterator> mp;
    LRUCache(int capacity) {
        cache.clear();
        mp.clear();
        cap=capacity;
    }
    
    void addValueToFront(int key,int val)
    {
        auto pos = mp[key];
        cache.erase(pos);
        cache.push_front({key,val});
        mp[key] = cache.begin();
    }

    int get(int key) {
        if(mp.find(key) != mp.end())
        {
            addValueToFront(key,(*mp[key]).second);
            return (*mp[key]).second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
            addValueToFront(key,value);
        else
        {
            cache.push_front({key,value});
            mp[key]=cache.begin();
            if(mp.size()>cap)
            {
                mp.erase(cache.back().first);
                cache.pop_back();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */