class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        int n=size(nums);
        if(n<=2)
            return 0;
        int prev=0;
        int ans=0;
        for(int i=2;i<n;i++)
        {
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
            {
                prev+=1;
                ans+=prev;
            }
            else
            {
                prev=0;
            }
        }
        return ans;
        
    }
};