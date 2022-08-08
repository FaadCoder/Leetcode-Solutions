class Solution
{
    vector<vector<int>> topDownDP;
    private:
            
        int lengthOfLISTopDown(vector<int> &nums,int idx, int prev)
        {
            if(idx==nums.size())
                return 0;
            
            if(topDownDP[idx][prev+10001]!=-1)
                return topDownDP[idx][prev+10001];
            
            
            int excludeCurrentElement = lengthOfLISTopDown(nums,idx+1,prev);
            int includeCurrentElement = 0;
            if(nums[idx]>prev)
                includeCurrentElement = 1+lengthOfLISTopDown(nums,idx+1,nums[idx]);
            
                return topDownDP[idx][prev+10001] = max(excludeCurrentElement, includeCurrentElement);
        }
        
        int lengthOfLISBinarySearch(vector<int> &nums)
        {
            vector<int> monotonicVector;

            for (int num: nums)
            {
                auto it = lower_bound(begin(monotonicVector), end(monotonicVector), num);
                if (it == monotonicVector.end())
                {
                    monotonicVector.push_back(num);
                }
                else
                {
                    *it = num;
                }
            }

            return (int) monotonicVector.size();
        }
        
    public:
        int lengthOfLIS(vector<int> &nums)
        {
            topDownDP.resize(nums.size()+1,vector<int>(20004,-1));
            
            return lengthOfLISTopDown(nums,0,-10001);
        }
};