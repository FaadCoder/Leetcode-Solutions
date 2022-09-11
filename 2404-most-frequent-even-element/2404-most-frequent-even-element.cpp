class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        
        for(int num : nums)
        {
            if(num % 2 == 0)
                freqMap[num] += 1;
        }
        
        if(freqMap.empty())
            return -1;
        
        int ans = INT_MAX;
        int mx = 0;
        for(auto it : freqMap)
        {
            if(it.second >= mx)
            {
                ans = (it.second == mx) ? min(ans, it.first) : it.first;
                mx = it.second;
            }
        }
        
        return ans;
    }
};