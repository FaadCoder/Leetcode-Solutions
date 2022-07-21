class Solution {
    
    int getPairsLessThanMid(int diff,vector<int> &nums)
    {
        int pairs = 0;
        int start = 0;
        for(int end = 0; end<nums.size(); end++)
        {
            while(abs(nums[start]-nums[end])>diff)
                start++;
            pairs += end-start;
        }
        return pairs;
    }
    
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int low = 0;
        int high = nums.back()-nums[0];
        
        while(low<high)
        {
            int mid = low + (high-low)/2;
            int numberOfPairs = getPairsLessThanMid(mid,nums);
            if(numberOfPairs<k)
                low = mid+1;
            else
                high = mid;
        }
        return low;
    }
};