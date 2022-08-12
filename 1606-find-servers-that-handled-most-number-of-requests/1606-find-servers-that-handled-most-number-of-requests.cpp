class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> result;
        unordered_map<int, int> serverReqCount;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        set<int> availableServers;
        
        //Assign the first k request to each server, add in PQ
        for(int i = 0; i < k && i < arrival.size(); i++)
        {
            pq.push({arrival[i] + load[i], i});
            serverReqCount[i]++;
        }
        
        for(int i = k; i < arrival.size(); i++)
        {
            if(availableServers.size() || (pq.size() && arrival[i] >= pq.top().first))
            {
                //Check if any other server got free.
                while(pq.size() && arrival[i] >= pq.top().first)
                {
                    //Add in to available list.
                    availableServers.insert(pq.top().second);
                    pq.pop();
                }
                
                //Find the first server in order.
                auto server = lower_bound(availableServers.begin(), availableServers.end(), i%k);
                
                //Roll over if no server found.
                if(server == availableServers.end())
                    server = availableServers.begin();
                
                //Update the ds.
                serverReqCount[*server]++;
                pq.push({arrival[i]+load[i], *server});                    
                
                //Remove from available list.
                availableServers.erase(server);                    
            }
        }
        
        
        //Get the max
        int maxr = INT_MIN;
        for(auto& sc: serverReqCount)
            maxr = max(maxr, sc.second);
        
        
        //There can be multiple servers with same req count.
        for(auto& sc: serverReqCount)
        {
            if(sc.second == maxr)
                result.push_back(sc.first);
        }
            
        return result;
    }
};