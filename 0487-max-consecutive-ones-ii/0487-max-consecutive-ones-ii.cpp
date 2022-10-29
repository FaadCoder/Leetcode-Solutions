class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int numberOfZerosFlipped = 0;
        int runningSum = 0;
        int maxConsecutiveOnes = 0;
        int start = 0;
        for(int end = 0; end < nums.size(); end++)
        {
            runningSum += 1;
            numberOfZerosFlipped += (nums[end] == 0);
            
            while(numberOfZerosFlipped > 1 and start <= end)
            {
                if(nums[start] == 0)
                    numberOfZerosFlipped -= 1;
                runningSum -= 1;
                start+=1;
            }
            
            maxConsecutiveOnes = max(maxConsecutiveOnes, runningSum);
        }
        
        return maxConsecutiveOnes;
    }
};