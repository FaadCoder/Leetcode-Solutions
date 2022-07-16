class Solution {
    
    int getPivot(vector<int> &nums,int low,int high)
    {
        int pivotElement = nums[high];
        int pivotIndex = low;
        
        for(int idx=low;idx<=high;idx++)
        {
            if(nums[idx]<pivotElement)
            {
                swap(nums[idx],nums[pivotIndex]);
                pivotIndex++;
            }
        }
        swap(nums[high],nums[pivotIndex]);
        return pivotIndex;
    }
    
    int getKthLargestElement(vector<int> &nums,int low,int high,int k)
    {
        int pivot = getPivot(nums,low,high);
        if(pivot==k)
            return nums[pivot];
        if(pivot>k)
            return getKthLargestElement(nums,low,pivot-1,k);
        return getKthLargestElement(nums,pivot+1,high,k);
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        return getKthLargestElement(nums,0,size(nums)-1,size(nums)-k);
            
    }
};