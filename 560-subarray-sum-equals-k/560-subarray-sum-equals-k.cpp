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
            auto it = hashMap.find(currentSum-k);
            if(it!=hashMap.end())
                totalSubarrays += it->second;
            hashMap[currentSum]++;
        }
        return totalSubarrays;
    }
};