class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int,vector<pair<int,double>>> graph;
        int idx = 0;
        for(auto &edge:edges)
        {
            graph[edge[0]].push_back({edge[1],succProb[idx]});
            graph[edge[1]].push_back({edge[0],succProb[idx++]});
        }
        
        priority_queue<pair<double,int>> maxHeap;
        
        vector<double> dist(n,0.0);
        
        maxHeap.push({(double)1.0,start});
        dist[start] = 1.0;
        
        while(!maxHeap.empty())
        {
            auto top = maxHeap.top();
            maxHeap.pop();
            double prob = top.first;
            int parent = top.second;
            if(prob<dist[parent])
                continue;
            
            if(parent==end)
                return prob;
            
            for(auto child:graph[parent])
            {
                double newProb = prob*child.second;
                if(dist[child.first]<newProb)
                {
                    dist[child.first] = newProb;
                    maxHeap.push({dist[child.first],child.first});
                }
            }
        }
        
        return 0.0;
    }
};