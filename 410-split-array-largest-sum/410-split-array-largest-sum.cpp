class Solution {
// Solution 1:
    bool isValidSplit(vector<int> &nums,int maxPossibleSum, int cuts)
    {
        int currentSum = 0;
        for(int num:nums)
        {
            if(num > maxPossibleSum)
            {
                return false;
            }
            currentSum += num;
            if(currentSum > maxPossibleSum)
            {
                cuts--;
                if(cuts < 0)
                    return false;
                currentSum = num;
            }
        }
        return true;
    }
    
    int getMinimumSumUsingBinarySearch(vector<int> &nums,int m)
    {
        int minVal = INT_MAX, maxVal = 0;
        
        for(int num:nums)
        {
            minVal = min(minVal,num);
            maxVal += num;
        }
        
        while(minVal < maxVal)
        {
            int mid = minVal + (maxVal - minVal) / 2;
            if(isValidSplit(nums, mid, m - 1))
            {
                maxVal = mid;
            }
            else
            {
                minVal = mid + 1;
            }
        }
        
        return minVal;
    }

// Solution 2:
    int getMinimumSum(vector<int> &nums,int m,vector<vector<int>> &dPTable,int currentIdx = 0)
    {
        if(currentIdx >= nums.size() and m==0)
            return 0;
        if(currentIdx >= nums.size() or m==0)
            return INT_MAX;
        int &cachedVal = dPTable[currentIdx][m];
        if(cachedVal != -1)
            return cachedVal;
        int currentSum = 0;
        int minSum = INT_MAX;
        for(int idx = currentIdx; idx<nums.size(); idx++)
        {
            currentSum += nums[idx];
            minSum = min(minSum,max(currentSum,getMinimumSum(nums,m-1,dPTable,idx+1)));
        }
        return cachedVal = minSum;
    }
    
    int getMinimumSumUsingDP(vector<int> &nums,int m)
    {
        vector<vector<int>> dPTable(nums.size()+1,vector<int>(m+1,-1));
        return getMinimumSum(nums,m,dPTable);
    }
    
public:
    int splitArray(vector<int>& nums, int m) 
    {
        return getMinimumSumUsingBinarySearch(nums,m);
        // return getMinimumSumUsingDP(nums,m);
    }
};