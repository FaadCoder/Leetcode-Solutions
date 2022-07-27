class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int maxReach = startFuel;
        
        priority_queue<int> fuelMaxHeap;
        int station = 0;
        int stops = 0;
        
        while(maxReach < target)
        {
            while(station < stations.size() and stations[station][0]<=maxReach)
                fuelMaxHeap.push(stations[station++][1]);
            
            if(fuelMaxHeap.empty())
                return -1;
            maxReach += fuelMaxHeap.top();
            fuelMaxHeap.pop();
            stops++;
        }
        return stops;
    } 
};