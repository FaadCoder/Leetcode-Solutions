class Solution
{
    public:
        int minMoves2(vector<int> &nums)
        {
            sort(nums.begin(), nums.end());
            
            int totalMinMoves = 0;
            int start = 0;
            int end = nums.size()-1;
            
            while(start < end)
                totalMinMoves += (nums[end--] - nums[start++]);
            return totalMinMoves;
        }
};