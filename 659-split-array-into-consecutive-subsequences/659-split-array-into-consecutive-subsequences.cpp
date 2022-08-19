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
            
            // If we have some sequence ending at num - 1 then we add our current num to the sequence
            if(subsequence[num-1] > 0)
            {
                // Because one of the sequence is now ending at num
                subsequence[num]++;
                subsequence[num-1]--;
            }
            else if(freq[num+1]>0 and freq[num+2]>0) // Lets make one sequence starting from current num
            {
                // We have used num, num + 1, num + 2 in the sequence so decrement their frequency
                freq[num+2]--;
                freq[num+1]--;
                
                // Because new Sequence will be ending at num + 2 (i.e, num, num+1, num+2)
                subsequence[num+2]++;
            }
            else
                return false;

            freq[num]--;
        }
        return true;
    }
};