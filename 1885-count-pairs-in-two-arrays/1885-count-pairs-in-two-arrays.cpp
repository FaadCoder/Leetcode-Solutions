#define ll long long int
class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        for(int idx=0;idx<nums1.size(); idx++)
            nums1[idx]-=nums2[idx];
        
        long long pairCount = 0;
        int start = 0, end = nums1.size()-1;
        sort(nums1.begin(),nums1.end());
        while(start<=end)
        {
            if(nums1[start]+nums1[end]>0)
            {
                pairCount+=end-start;
                end--;
            }
            else
            {
                start++;
            }
        }
        
        return pairCount;
    }
};