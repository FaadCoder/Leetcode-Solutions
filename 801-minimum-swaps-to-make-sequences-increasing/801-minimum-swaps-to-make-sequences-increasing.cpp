class Solution {
    int dp[100002][2];
    
    int getMinSwaps(vector<int> &nums1,vector<int> &nums2,int idx=0,int swaps=0)
    {
        if(idx>=nums1.size())
            return 0;
        
        if(dp[idx][swaps]!=-1)
            return dp[idx][swaps];
        
        int ans = INT_MAX-1;
        
        if(nums1[idx]>(idx>0 ? nums1[idx-1] : -1) and nums2[idx] > (idx>0 ? nums2[idx-1] : -1))
            ans = min(ans,getMinSwaps(nums1,nums2,idx+1,0));
        swap(nums1[idx],nums2[idx]);
        if(nums1[idx]>(idx>0 ? nums1[idx-1] : -1) and nums2[idx] > (idx>0 ? nums2[idx-1] : -1))
            ans = min(ans, 1 + getMinSwaps(nums1,nums2,idx+1,1));
        swap(nums1[idx],nums2[idx]);
        return dp[idx][swaps] = ans;
    }
    
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
        memset(dp,-1,sizeof(dp));
        return getMinSwaps(nums1,nums2);
    }
};