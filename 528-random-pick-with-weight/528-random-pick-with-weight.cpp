class Solution {
    vector<int> probabilityDistributionVector;
public:
    Solution(vector<int>& w) {
        probabilityDistributionVector.push_back(w[0]);
        for(int idx = 1; idx<w.size(); idx++)
        {
            probabilityDistributionVector.push_back(probabilityDistributionVector.back()+w[idx]);
        }
    }
    
    int pickIndex() {
        int randIndex = rand()%(probabilityDistributionVector.back()) + 1;
        return lower_bound(probabilityDistributionVector.begin(),probabilityDistributionVector.end(),randIndex) -probabilityDistributionVector.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */