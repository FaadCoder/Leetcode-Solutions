class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freqHashMap;
        
        int totalElements = arr.size();
        
        for(int num:arr)
            freqHashMap[num]++;
        
        priority_queue<int> maxHeap;
        
        for(auto it:freqHashMap)
            maxHeap.push(it.second);
        
        int elementsRemoved = 0;
        
        while(!maxHeap.empty())
        {
            totalElements -= maxHeap.top();
            elementsRemoved++;
            maxHeap.pop();
            if(totalElements <= arr.size()/2)
                break;
        }
        
        return elementsRemoved;
    }
};