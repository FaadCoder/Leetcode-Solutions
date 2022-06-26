class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int numberOfCards = cardPoints.size();
        int windowSize = numberOfCards - k;
        int totalSum = accumulate(cardPoints.begin(),cardPoints.end(),0);
        int currSum = 0;
        int minSum = INT_MAX;
        for(int idx = 0; idx<windowSize; idx++)
            currSum += cardPoints[idx];
        minSum = min(minSum,currSum);
        
        for(int idx = windowSize; idx<numberOfCards; idx++)
        {
            currSum -= cardPoints[idx - windowSize];
            currSum += cardPoints[idx];
            minSum = min(minSum,currSum);
        }
        
        return totalSum - minSum;
    }
};