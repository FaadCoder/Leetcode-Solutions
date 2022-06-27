class Solution {
public:
    int minPartitions(string n) {
        int maxNumber = INT_MIN;
        for(char ch:n)
        {
            maxNumber = max(maxNumber,ch-'0');
        }
        return maxNumber;
    }
};