class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int len = 1;
        
        int start = 0;
        multiset<int> orderedSet;
        
        for(int end = 0; end < nums.size(); end++)
        {
            while(start<end and orderedSet.size() and (abs(*orderedSet.begin() - nums[end]) > limit or abs(*orderedSet.rbegin() - nums[end]) > limit))
            {
                orderedSet.erase(orderedSet.find(nums[start]));
                start+=1;
            }
            orderedSet.insert(nums[end]);
            len = max(len, end - start + 1);
        }
        
        return len;
        
    }
};
