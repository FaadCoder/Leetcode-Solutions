class Solution {
public:
    int dp[1000][101][2] = {};
    int dfs(vector<int>& ps, int p, int k, bool buy) {
        if (p >= ps.size() || (k == 0 && buy))
            return 0;
        if (dp[p][k][buy] == 0)
            dp[p][k][buy] = max(dfs(ps, p + 1, k, buy), 
                (buy ? -1 : 1) * ps[p] + dfs(ps, p + 1, k - buy, !buy));
        return dp[p][k][buy];
    } 
    int maxProfit(int k, vector<int>& ps) {
        if (k * 2 >= ps.size()) 
            return maxProfit2(ps);
        return dfs(ps, 0, k, true);
     }
    int maxProfit2(vector<int>& ps, int res = 0) {
        for (auto i = 1; i < ps.size(); ++i) 
            res += max(0, ps[i] - ps[i - 1]);
        return res;
    }
};