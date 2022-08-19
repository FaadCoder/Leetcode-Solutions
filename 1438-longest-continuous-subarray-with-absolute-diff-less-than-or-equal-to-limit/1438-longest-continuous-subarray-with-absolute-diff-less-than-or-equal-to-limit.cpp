class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int len = 1;
        
        int start = 0;
        multiset<int> orderedSet;
        
        for(int end = 0; end < nums.size(); end++)
        {
            orderedSet.insert(nums[end]);
            while(orderedSet.size() and abs(*orderedSet.begin() - *orderedSet.rbegin()) > limit)
            {
                orderedSet.erase(orderedSet.find(nums[start]));
                start+=1;
            }
            len = max(len, end - start + 1);
        }
        
        return len;
        
    }
};
