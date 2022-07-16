class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(int stick:sticks)
            minHeap.push(stick);
        int cost = 0;
        while(minHeap.size()>1)
        {
            int top1 = minHeap.top();
            minHeap.pop();
            int top2 = minHeap.top();
            minHeap.pop();
            cost+=top1+top2;
            minHeap.push(top1+top2);
        }
        return cost;
    }
};