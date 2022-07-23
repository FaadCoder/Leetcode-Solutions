class Solution {
    int count = 0;
    
    void mergeBothHalves(vector<int> &nums,int start,int mid,int end)
    {
        int left = start;
        int right = mid+1;
        while(left<=mid and right<=end)
        {
            if((long)nums[left]>(long)2*nums[right])
            {
                count += (mid-left+1);
                right++;
            }
            else
            {
                left++;
            }
        }
        
        vector<int> temp(end-start+1,0);
        
        left = start;
        right = mid+1;
        int idx = 0;
        while(left<=mid and right<=end)
        {
            if(left<=mid and nums[left]<nums[right])
            {
                temp[idx++]=nums[left++];
            }
            else
            {
                temp[idx++] = nums[right++];
            }
        }
        
        while(left<=mid)
            temp[idx++]=nums[left++];
        
        while(right<=end)
            temp[idx++]=nums[right++];
        
        idx = 0;
        for(int i=start;i<=end;i++)
            nums[i] = temp[idx++];
        
    }
    
    void mergeSort(vector<int> &nums,int start,int end)
    {
        if(start==end)
            return;
        int mid = start + (end-start)/2;
        mergeSort(nums,start,mid);
        mergeSort(nums,mid+1,end);
        mergeBothHalves(nums,start,mid,end);
    }
    
public:
    int reversePairs(vector<int>& nums) {
        count = 0;
        mergeSort(nums,0,nums.size()-1);
        return count;
    }
};