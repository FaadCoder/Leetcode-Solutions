class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int len = 1;
        
        int start = 0;
        deque<int> maxDeque, minDeque;
        
        for(int end = 0; end < nums.size(); end++)
        {
            
            while(!maxDeque.empty() and nums[end] > maxDeque.back()) maxDeque.pop_back();
            while(!minDeque.empty() and nums[end] < minDeque.back()) minDeque.pop_back();
            
            maxDeque.push_back(nums[end]);
            minDeque.push_back(nums[end]);
            
            while(start < end and maxDeque.size() and minDeque.size() and abs(maxDeque.front() - minDeque.front()) > limit)
            {
                if(maxDeque.front() == nums[start])
                    maxDeque.pop_front();
                if(minDeque.front() == nums[start])
                    minDeque.pop_front(); 
                
                start+=1;
            }
            len = max(len, end - start + 1);
        }
        
        return len;
        
    }
};
