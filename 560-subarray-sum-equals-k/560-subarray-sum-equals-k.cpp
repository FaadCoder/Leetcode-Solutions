class Solution {
public:
    
    
    int subarraySum(vector<int>& nums, int k) {
        int totalSubarrays = 0;
        unordered_map<int,int> hashMap;
        hashMap[0] = 1;
        int currentSum = 0;
        for(int num:nums)
        {
            currentSum += num;
            totalSubarrays += hashMap[currentSum - k];
            hashMap[currentSum]++;
        }
        return totalSubarrays;
    }
};