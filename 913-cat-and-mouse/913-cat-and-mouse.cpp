static auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<vector<int>>> dp;
    vector<vector<vector<int>>> out_degree;
    vector<int> cat_degree;
    
    void recur(vector<vector<int>> &graph, int mouse, int cat, int turn, int result){
        if (dp[turn][mouse][cat]!=0) return;
        // cout<<turn<<" "<<mouse<<" "<<cat<<" "<<(result==1?"Mouse":"Cat")<<endl;
        dp[turn][mouse][cat]=result;
        if (turn){
            turn=0;
            for (int j:graph[mouse]){
                if (j==0 || j==cat){
                    continue;
                }
                if (result==1){
                    recur(graph, j, cat, turn, result);
                }
                else{
                    out_degree[turn][j][cat]++;
                    if (out_degree[turn][j][cat]==graph[j].size()) recur(graph, j, cat, turn, 2);
                }
            }
        }
        else{
            turn=1;
            for (int j:graph[cat]){
                if (j==0 || j==mouse){
                    continue;
                }
                if (result==2){
                    recur(graph, mouse, j, turn, result);
                }
                else{
                    out_degree[turn][mouse][j]++;
                    if (out_degree[turn][mouse][j]==cat_degree[j]) recur(graph, mouse, j, turn, 1);
                }
            }
        }
    }
    
    int catMouseGame(vector<vector<int>>& graph) {
        int n=graph.size();
        cat_degree=vector<int> (n);
        dp=vector<vector<vector<int>>>(2, vector<vector<int>>(n, vector<int>(n, 0)));
        out_degree=vector<vector<vector<int>>>(2, vector<vector<int>>(n, vector<int>(n, 0)));;
        
        for (int i=1; i<n; ++i){
            cat_degree[i]=graph[i].size();
        }
        for (int i:graph[0]) cat_degree[i]--;
        
        
        for (int i=1; i<n; ++i){
            for (int turn:{0, 1}){
                recur(graph, 0, i, turn, 1);
                recur(graph, i, i, turn, 2);
            }
        }
        return dp[0][1][2];
    }
};