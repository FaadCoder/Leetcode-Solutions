class StockPrice {
    unordered_map<int,int> hashMap;
    multiset<int> priceSet;
    int latestTimestamp = 0;
public:
    StockPrice() {
        hashMap.clear();
        priceSet.clear();
        latestTimestamp = 0;
    }
    
    void update(int timestamp, int price) {
        if(hashMap.count(timestamp))
            priceSet.erase(priceSet.find(hashMap[timestamp]));
        hashMap[timestamp] = price;
        latestTimestamp = max(latestTimestamp,timestamp);
        priceSet.insert(price);
    }
    
    int current() {
        return hashMap[latestTimestamp];
    }
    
    int maximum() {
        return *priceSet.rbegin();
    }
    
    int minimum() {
        return *priceSet.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */