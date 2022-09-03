class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int i = 0;
        long long currSum = 0;
        long long cost = 0;
        int ans = 0;
        
        multiset<int> orderedSet;
        for(int j = 0; j<chargeTimes.size(); j++)
        {
            orderedSet.insert(chargeTimes[j]);
            cost += runningCosts[j];
            currSum = (*orderedSet.rbegin()) + (j - i + 1) * (cost);
            
            while(currSum > budget and i<=j)
            {
                cost -= runningCosts[i];
                orderedSet.erase(orderedSet.find(chargeTimes[i]));
                i+=1;
                if(!orderedSet.empty())
                    currSum = (*orderedSet.rbegin()) + (j - i + 1) * (cost);
                else
                    currSum = 0;
            }
            
            ans = max(ans, j - i + 1);
        }
        
        return ans;
    }
};