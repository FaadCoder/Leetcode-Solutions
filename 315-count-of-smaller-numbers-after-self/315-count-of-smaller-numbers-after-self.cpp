class Solution {
    void mergeBothHalves( vector<pair<int,int>> &nums,vector<int> &count,int start,int mid,int end)
    {
        int left = start;
        int right = mid+1;
        int inversionCount = 0;
        vector<pair<int,int>> temp(end-start+1);
        int idx = 0;
        while(left<=mid and right<=end)
        {
            if(nums[left].first <= nums[right].first)
            {
                count[nums[left].second]+=inversionCount;
                temp[idx] = nums[left];
                idx++,left++;
            }
            else
            {
                inversionCount+=1;
                temp[idx] = nums[right];
                idx++,right++;
            }
            
        }
        while(left<=mid)
        {
            count[nums[left].second]+=inversionCount;
            temp[idx] = nums[left];
            idx++,left++;
        }   
        
        while(right<=end)
        {
            temp[idx] = nums[right];
                idx++,right++;
        }
        
        idx = 0;
        for(int i=start;i<=end;i++)
            nums[i] = temp[idx++];
        
    }
    
    void mergeSort( vector<pair<int,int>> &nums,vector<int> &count,int start,int end)
    {
        if(start>=end)
            return;
        int mid = start + (end-start)/2;
        mergeSort(nums,count,start,mid);
        mergeSort(nums,count,mid+1,end);
        mergeBothHalves(nums,count,start,mid,end);
    }
    
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        if(!nums.size())
            return {};
        vector<pair<int,int>> newNums;
        for(int idx=0;idx<nums.size();idx++)
            newNums.push_back({nums[idx],idx});
        
        vector<int> count(nums.size(),0);
        
        mergeSort(newNums,count,0,nums.size()-1);
        
        return count;
    }
};