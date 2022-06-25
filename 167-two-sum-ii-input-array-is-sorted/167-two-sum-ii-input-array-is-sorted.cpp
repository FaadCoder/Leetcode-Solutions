class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int startPtr = 0;
        int endPtr = numbers.size()-1;
        
        while(startPtr < endPtr)
        {
            int numberAtStartPtr = numbers[startPtr];
            int numberAtEndPtr = numbers[endPtr];
            int currentSum = numberAtStartPtr + numberAtEndPtr;
            if(currentSum == target)
                return {startPtr + 1,endPtr + 1};
            
            if(currentSum > target)
                endPtr -= 1;
            else
                startPtr += 1;
        }
        
        return {};
    }
};