class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        
        for(int stone:stones)
            maxHeap.push(stone);
        while(maxHeap.size()>1)
        {
            int stone1 = maxHeap.top();
            maxHeap.pop();
            int stone2 = maxHeap.top();
            maxHeap.pop();
            if(stone1!=stone2)
            {
                maxHeap.push(max(stone1,stone2)-min(stone1,stone2));
            }
                
        }
        
        return maxHeap.empty()?0:maxHeap.top();
    }
};