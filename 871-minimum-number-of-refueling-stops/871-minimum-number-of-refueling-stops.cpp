class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        // Represents the current distance travelled.
        int currentDistance = startFuel;
        
        // idx -> represent the stations current idx
        int idx = 0;
        
        //Max heap to store max fuel
        priority_queue<int> maxHeap;
        
        // Store min Stops
        int minStops = 0;
        
        while(currentDistance < target)
        {
            // Store fuels of all the stations whose distance is less than equals to currentDistance
            while(idx < stations.size() and stations[idx][0] <= currentDistance)
                maxHeap.push(stations[idx++][1]);
            
            // If there are no stations available such that we can reach target from current distance
            if(maxHeap.empty())
                return -1;
            
            // Use the Max fuel from available fuels in order to cover max distance
            currentDistance += maxHeap.top();
            maxHeap.pop();
            
            // we have refilled fuel above
            minStops += 1;
        }
        
        return minStops;
    }
};