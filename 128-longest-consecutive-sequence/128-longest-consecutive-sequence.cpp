class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet(nums.begin(),nums.end());
        
        int longestConsecutiveSequenceLength = 0;
        for(int element:nums)
        {
            if(hashSet.count(element-1))
                continue;
            
            int currentConsecutiveSequenceLength = 1;
            
            while(hashSet.count(element+1))
            {
                currentConsecutiveSequenceLength+=1;
                element += 1;
            }
            longestConsecutiveSequenceLength = max(longestConsecutiveSequenceLength,currentConsecutiveSequenceLength);
        }
        
        return longestConsecutiveSequenceLength;
    }
};

/*

1,2,3,4,100,200


*/
    