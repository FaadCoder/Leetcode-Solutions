class HitCounter {
    
    queue<int> timestampQueue;
    
    
public:
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        timestampQueue.push(timestamp);
    }
    
    int getHits(int timestamp) {
        while(!timestampQueue.empty() and timestamp - timestampQueue.front() >= 300)
        {
            timestampQueue.pop();
        }
        
        return timestampQueue.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */