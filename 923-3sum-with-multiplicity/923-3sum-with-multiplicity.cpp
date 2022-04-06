class Solution {
private:
    const int MOD = 1e9+7;
    int moduloAddition(int a,int b)
    {
        return (a%MOD + b%MOD)%MOD;
    }
public:
    int threeSumMulti(vector<int>& arr, int target) 
    {
        unordered_map<int,int> vis;
        int ans = 0;
        for(int lastIdx=0; lastIdx<arr.size(); lastIdx++)
        {
            ans = moduloAddition(ans,vis[target-arr[lastIdx]]);
            for(int idx=0;idx<lastIdx;idx++)
            {
                vis[arr[idx]+arr[lastIdx]]++;
            }
        }
        return ans;
    }
};