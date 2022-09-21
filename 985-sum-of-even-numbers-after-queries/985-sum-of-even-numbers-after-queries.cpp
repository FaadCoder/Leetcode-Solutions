class Solution {
    
    bool isOdd(int num)
    {
        num = abs(num);
        return (num % 2 == 1);
    }
    
    bool isEven(int num)
    {
        num = abs(num);
        return (num % 2 == 0);
    }
    
    
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int evenSum = 0;
        
        for(int num : nums)
            evenSum += (num & 1) ? 0 : num;
        
        vector<int> queriesResult;
        
        for(vector<int> &query : queries)
        {
            int index = query[1];
            int currentValue = nums[index];
            int newValue = query[0] + currentValue;
            nums[index] = newValue;
            
            if (isOdd(currentValue) and isEven(newValue))
            {
                evenSum += newValue;
            }
            else if(isEven(currentValue) and isEven(newValue))
            {
                evenSum -= currentValue;
                evenSum += newValue;
            }
            else if(isEven(currentValue) and isOdd(newValue))
            {
                evenSum -= currentValue;
            }
            
            queriesResult.push_back(evenSum);
        }
        
        return queriesResult;
    }
};