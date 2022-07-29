class Solution {
    vector<vector<int> > adj;  // adjacency list
    int n;
    int k;
    vector<int> dp;
    int solve(int mask)
    {
        if(mask==((1<<n)-1))
        {  // All courses are taken
            return 0;
        }
        if(dp[mask]!=-1)   // memoization
            return dp[mask];
        vector<int> indeg(n,0);
        for(int i=0; i<n; i++)
        {
            if(mask&(1<<i))
                continue;
            for(auto it: adj[i])
            {
                indeg[it]++;
            }
        }
        int temp=0;  // For a mask of all nodes with 0-indegree
        for(int i=0; i<n; i++)
        {
            if(indeg[i]==0&&!(mask&(1<<i)))
            {
                temp=temp|(1<<i);
            }
        }
        int j=temp;
        int cnt=__builtin_popcount(j);  // count of nodes with 0-indegree

        int ans=n+1;  // ans will be 'n' in the worst case, so take (n+1) as infinity 
        if(cnt>k)
        {
            for( ; j ; j=(j-1)&temp )  // iterate through all submasks of temp
            {
                cnt=__builtin_popcount(j);  
                if(cnt!=k)   
                    continue;
                ans=min(ans,1+solve(mask|j));                   
            }
        }
        else
        {
            ans=min(ans,1+solve(mask|j));
        }
        return dp[mask]=ans;
    }
    
    public:
    int minNumberOfSemesters(int N, vector<vector<int>>& d, int K) {
        n=N;
        k=K;
        dp.assign(1<<n,-1);
        adj.clear();
        adj.resize(n);
        for(int i=0; i<d.size(); i++)
        {
            d[i][0]--;
            d[i][1]--;
            adj[d[i][0]].push_back(d[i][1]);
        }
        return solve(0);
    }
};