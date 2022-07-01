struct Edge{
    int destination;
    int time;
    Edge(int _destination, int _time)
    {
        destination = _destination;
        time = _time;
    }
};

class Solution {
    
    void formGraph(vector<vector<int>>& times, int n,vector<Edge> graph[])
    {
        for(auto &time:times)
           graph[time[0]-1].push_back(Edge(time[1]-1,time[2]));
    }
    
    bool isSignalReceivedByAllNodes(vector<int> &dis,int n)
    {
        for(int ele:dis)
        {
            if(ele == INT_MAX)
                return false;
        }
        return true;
    }
    
    int getMaxTimeUsingBfs(vector<Edge> graph[],int k,int n)
    {
        queue<int> bfsQueue;
        vector<int> dis(n,INT_MAX);
        bfsQueue.push(k);
        dis[k] = 0;
        
        while(!bfsQueue.empty())
        {
            int source = bfsQueue.front();
            bfsQueue.pop();
            
            for(Edge child:graph[source])
            {
                int destination = child.destination;
                int childTime = child.time;
                if(dis[destination] > childTime + dis[source])
                {
                    dis[destination] = childTime + dis[source];
                    bfsQueue.push(destination);
                }
            }
        }
        
        bool didAllNodesReceiveSignal = isSignalReceivedByAllNodes(dis,n);

        return didAllNodesReceiveSignal ? *max_element(dis.begin(),dis.end()) : -1;
    }
    
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<Edge> graph[n];
        formGraph(times,n,graph);
        int maxTime = getMaxTimeUsingBfs(graph,k-1,n);
        
        return maxTime;
    }
};