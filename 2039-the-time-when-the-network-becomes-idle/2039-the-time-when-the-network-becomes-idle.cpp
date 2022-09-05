class Solution {
    unordered_map<int, vector<int>> graph;
    vector<int> dis;
    
    void buildGraph(vector<vector<int>> &edges)
    {
        graph.clear();
        
        for(auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
    }
    
    void populateDistances()
    {
        queue<int> q;
        q.push(0);
        dis[0] = 0;
        
        while(!q.empty())
        {
            int par = q.front();
            q.pop();
            
            for(auto &child : graph[par])
            {
                if(dis[child] == -1)
                {
                    dis[child] = dis[par] + 1;
                    q.push(child);
                }
            }
        }
    }
    
    int getMaxTime(vector<int> &patience)
    {
        int maxTime = 0;
        
        for(int server = 1; server < patience.size(); server+=1)
        {
            int roundTripTime = 2 * dis[server];
            int waitingTime = roundTripTime - 1;
            int numberOfMessages = waitingTime / patience[server];
            maxTime = max(maxTime, roundTripTime + numberOfMessages * patience[server]);
        }
        
        return maxTime + 1;
    }
    
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        buildGraph(edges);
        dis.resize(patience.size(), -1);
        populateDistances();
        return getMaxTime(patience);
    }
};

/*

dis[1] = 1  -> [2]
dis[2] = 2  -> [1]


server 2 :  
firstMessageReceiveBack = 2 * dis[2] = 4
waitingTime = 2 * dis[2] - 1 = 4 - 1 = 3
numberOfMessagesSentInBetween = (waitingTime) / patience[2] = 3 / 1 = 3

TimeTakenByLastMessage = numberOfMessagesSentInBetween * patience[2] = 3 * 1 = 3

totalTime = 4 + 3  = 7 

*/