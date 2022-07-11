class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int,int> hashMap;
        int maxLength = 1;
        for(int ele:arr)
        {
            if(hashMap.count(ele-diff))
            {
                hashMap[ele] = 1 + hashMap[ele - diff];
            }
            else
            {
                hashMap[ele] = 1;
            }
            maxLength = max(maxLength,hashMap[ele]);
        }
        
        return maxLength;
    }
};