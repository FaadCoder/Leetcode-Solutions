class Solution {
public:
    int longestCycle(vector<int>& edges) 
    {
        int maxLen = -1;
        bool vis[edges.size()];
        memset(vis,false,sizeof(vis));
        for(int vertex = 0; vertex < edges.size(); vertex++)
        {
            if(vis[vertex])
                continue;
            int dis = 0;
            unordered_map<int,int> hashMap;
            int nextVertex = vertex;
            while(nextVertex!=-1)
            {
                if(hashMap.count(nextVertex))
                {
                    maxLen = max(maxLen, dis-hashMap[nextVertex]);
                    break;
                }
                if(vis[nextVertex])
                    break;
               
                vis[nextVertex] = true;
                hashMap[nextVertex] = dis++;
                nextVertex = edges[nextVertex];
            }
        }
        
        return maxLen;
    }
};