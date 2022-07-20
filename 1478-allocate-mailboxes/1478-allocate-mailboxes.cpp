class Solution {
    int cost[102][102] = {};
    int dp[102][102] = {};
    
    int getMinDistance(vector<int> &houses,int start,int k)
    {
        
        if(start>=houses.size() and k==0)
            return 0;
        
        if(start>=houses.size() or k==0)
            return INT_MAX/2;
        
        if(dp[start][k]!=-1)
            return dp[start][k];
        
        int minDistance = INT_MAX/2;
        
        // Try to put one mail box in range [start,end]
        // Compare all the costs and store minimum cost
        for(int end = start; end<houses.size(); end++)
            minDistance = min(minDistance,cost[start][end]+getMinDistance(houses,end+1,k-1));
        
        // Return the minimum distance from all the posibilities.
        return dp[start][k] = minDistance;
    }
    
public:
    int minDistance(vector<int>& houses, int k) 
    {
        sort(houses.begin(),houses.end());
        int numberOfHouses = houses.size();
        // Make the Range of houses to include, let say [start,end](Inclusive)
        // Get the cost of mailbox that is put in between the range [start.....end]
        for(int start = 0; start<numberOfHouses; start++)
        {
            for(int end = start; end<numberOfHouses; end++)
            {
                // Get the median house.
                int medianHouseDistance = houses[(start+end)/2];
                
                // Iterate through all the houses in the range and get the distance from median house
                for(int house=start; house<=end; house++)
                    cost[start][end] += abs(houses[house]-medianHouseDistance);
            }
        }
        memset(dp,-1,sizeof(dp));
        return getMinDistance(houses,0,k);
    }
};