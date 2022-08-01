class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if(size(nums) < 3)
            return false;
        
        // Step 1: Get Frequency of Num in nums
        unordered_map<int,int> freq;
        for(int num:nums)
            freq[num]++;
        
        // Step 2: Need a map for subsequences ending at current index
        unordered_map<int,int> subsequence;
        
        // Step 3: try to form subsequence from each num
        
        for(int num:nums)
        {
            // if the num is already visited/processed before
            if(freq[num]==0)
                continue;
            else if(subsequence[num-1]>0)
            {
                subsequence[num]++;
                subsequence[num-1]--;
            }
            else if(freq[num+1]>0 and freq[num+2]>0)
            {
                freq[num+2]--;
                freq[num+1]--;
                subsequence[num+2]++;
            }
            else
                return false;

            freq[num]--;
        }
        return true;
    }
};