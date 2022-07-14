class Solution {
    
    bool isPossible(int leastSweetness,vector<int> &sweetness,int k)
    {
        int numberOfPeople = k+1;
        int peopleWithChocolates = 0;
        int currentSweetness = 0;
        for(auto sweet:sweetness)
        {
            currentSweetness += sweet;
            if(currentSweetness>=leastSweetness)
            {
                peopleWithChocolates += 1;
                currentSweetness = 0;
            }
        }
        return peopleWithChocolates >= numberOfPeople;
    }
    
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int low = *min_element(sweetness.begin(),sweetness.end());
        int high = accumulate(sweetness.begin(),sweetness.end(),0);
        int maxSweetness = low;
        
        while(low<=high)
        {
            int mid = low + (high - low)/2;
            if(isPossible(mid,sweetness,k))
            {
                maxSweetness = mid;
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        
        return maxSweetness;
    }
};