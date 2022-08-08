class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> monotonicVector;
        
        for(int num:nums)
        {
            auto it = lower_bound(begin(monotonicVector),end(monotonicVector),num);
            if(it==monotonicVector.end())
            {
                monotonicVector.push_back(num);
            }
            else
            {
                *it = num;
            }
        }
        
        return (int)monotonicVector.size();
    }
};