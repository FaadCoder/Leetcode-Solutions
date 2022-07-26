class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff(gas.size());
        int totalTank = 0;
        int currentTank = 0;
        int startingIdx = 0;
        for(int idx=0;idx<size(gas);idx++)
        {
            totalTank += gas[idx]-cost[idx];
            currentTank += gas[idx]-cost[idx];
            if(currentTank<0)
            {
                currentTank = 0;
                startingIdx = idx+1;
            }
        }
    
     
        return totalTank>=0?startingIdx:-1;
    }
};