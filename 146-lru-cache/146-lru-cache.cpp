class LRUCache {
private:
    // Lru Cache list to store key,value pair
    // least recently used/accessed nodes will be at the end of the cache.
    list<pair<int,int>> cache;
    // Key to DLL Node's mapping
    unordered_map<int,list<pair<int,int>>::iterator> frequentAccessMap;
    // Max Capacity
    int maxCap;

    void refreshCache(int key,int val)
    {
        auto pos = frequentAccessMap[key];
        cache.erase(pos);
        cache.push_front({key,val});
        frequentAccessMap[key] = cache.begin();
    }


public:
    LRUCache(int capacity) {
        cache.clear();
        frequentAccessMap.clear();
        maxCap = capacity;
    }
    
    int get(int key) {
        if(frequentAccessMap.count(key))
        {
            int val = (*frequentAccessMap[key]).second;
            refreshCache(key,val);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
        if(frequentAccessMap.count(key))
        {
            refreshCache(key,value);
        }
        else
        {
            cache.push_front({key,value});
            frequentAccessMap[key] = cache.begin();
            if(cache.size()>maxCap)
            {
                frequentAccessMap.erase(cache.back().first);
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