class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int numberOfElements = arr.size();
        map<int,int> valueToIndexMap;
        
        vector<bool> oddJump(numberOfElements,false);
        vector<bool> evenJump(numberOfElements,false);
        
        oddJump[numberOfElements - 1] = true;
        evenJump[numberOfElements - 1] = true;
        
        valueToIndexMap[arr.back()] = numberOfElements-1;
        int goodIndices = 1;
        
        for(int idx = numberOfElements - 2; idx>=0; idx--)
        {
            auto nextOddJumpIndex = valueToIndexMap.lower_bound(arr[idx]);
            auto nextEvenJumpIndex = valueToIndexMap.upper_bound(arr[idx]);
            
            if(nextOddJumpIndex!=valueToIndexMap.end())
            {
                oddJump[idx] = evenJump[nextOddJumpIndex->second];
            }
            
            if(nextEvenJumpIndex!=valueToIndexMap.begin())
            {
                nextEvenJumpIndex--;
                evenJump[idx] = oddJump[nextEvenJumpIndex->second];
            }
            
            if(oddJump[idx])
                goodIndices+=1;
            
            valueToIndexMap[arr[idx]] = idx;
        }
        return goodIndices;
    }
};