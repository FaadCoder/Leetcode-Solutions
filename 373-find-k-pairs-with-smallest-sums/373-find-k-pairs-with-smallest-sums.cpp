struct Pair{
    int num1;
    int num2;
    int num2Idx;
    
    Pair(int _num1, int _num2, int _num2Idx): num1(_num1), num2(_num2), num2Idx(_num2Idx){}
};

struct Comparator{
    bool operator()(Pair &p1, Pair &p2){
        return p1.num1 + p1.num2 > p2.num1 + p2.num2;
    }
};

class Solution {
    
    
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<Pair, vector<Pair>, Comparator> minHeap;
        vector<vector<int>> ans;
        
        for(int num1:nums1)
            minHeap.push(Pair(num1, nums2[0], 0));
        
        while(k > 0 and !minHeap.empty())
        {
            k-=1;
            auto top = minHeap.top();
            minHeap.pop();
            ans.push_back({top.num1, top.num2});
            
            if(top.num2Idx + 1 < nums2.size())
                minHeap.push(Pair(top.num1, nums2[top.num2Idx + 1], top.num2Idx + 1));
        }
        
        return ans;
    }
};