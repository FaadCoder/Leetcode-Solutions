class Solution {
    const int MOD = 1e9+7;
    set<int> hashSet;
    unordered_map<int,int> dp;
    
    int addUnderMod(int a,int b)
    {
        return (a%MOD + b%MOD)%MOD;
    }
    
    int mulUnderMod(long long int a,long long int b)
    {
        return (a%MOD * b%MOD)%MOD;
    }
    
    int getTotalTrees(int root)
    {
        if(dp.count(root))
            return dp[root];
        
        int total = 1;
        for(int num:hashSet)
        {
            if((root % num == 0) and hashSet.count(root/num))
                total = addUnderMod(total, mulUnderMod(getTotalTrees(num), getTotalTrees(root/num)));
        }
        
        return dp[root] = total;
    }
    
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        hashSet.clear();
        hashSet = set<int>(begin(arr),end(arr));
        int totalTrees = 0;
        
        for(int num:hashSet)
            totalTrees = addUnderMod(totalTrees, getTotalTrees(num));
        
        return totalTrees;
    }
};