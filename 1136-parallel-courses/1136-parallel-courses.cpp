class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<int> indegree(n,0);
        vector<int> graph[n];
        for(auto &relation:relations)
        {
            graph[relation[0]-1].push_back(relation[1]-1);
            indegree[relation[1]-1]++;
        }
        
        
        queue<int> bfsQueue;
        int count = 0;
        int minSemesters = 0;
        for(int vertex = 0; vertex<n; vertex++)
        {
            if(indegree[vertex] == 0)
                bfsQueue.push(vertex);
        }
        
        while(!bfsQueue.empty())
        {
            int numberOfNodesAtCurrentLevel = bfsQueue.size();
            while(numberOfNodesAtCurrentLevel--)
            {
                int source = bfsQueue.front();
                bfsQueue.pop();
                count++;
                for(auto &child:graph[source])
                {
                    indegree[child]--;
                    if(indegree[child] == 0)
                        bfsQueue.push(child);
                }
            }
            minSemesters+=1;
        }
        
        return (count == n) ? minSemesters : -1;
    }
};