class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totalSize = cardPoints.size();
        int windowSize = totalSize - k;
        
        int totalSum = accumulate(begin(cardPoints),end(cardPoints),0);
        
        int currSum = 0;
        int minScore = INT_MAX;
        
        for(int end = 0; end<totalSize; end++)
        {
            currSum += cardPoints[end];
            if(end >= windowSize)
                currSum -= cardPoints[end - windowSize];
            
            if(end >= windowSize-1)
                minScore = min(minScore, currSum);
            
        }
        
        return totalSum - minScore;
        
    }
};