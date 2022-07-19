class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.empty())
            return ans;
        
        sort(nums.begin(),nums.end());
        int firstNumberIdx = 0;
        while(firstNumberIdx<=nums.size()-2)
        {
            int firstNumber = nums[firstNumberIdx];
            int start = firstNumberIdx+1;
            int end = nums.size()-1;
            int target = -firstNumber;
            while(start<end)
            {
                int secondNumber = nums[start];
                int endNumber = nums[end];
                
                int currentSum = secondNumber + endNumber;

                if(currentSum==target)
                {
                    
                    ans.push_back({firstNumber,nums[start],nums[end]});
                    
                    while(start<end and nums[start]==secondNumber)
                        start++;
                    while(start<end and nums[end]==endNumber)
                        end--;
                }
                else if(currentSum<target)
                    start++;
                else
                    end--;
            }
            while(firstNumberIdx<=nums.size()-2 and firstNumber==nums[firstNumberIdx])
                firstNumberIdx++;
        }
        return ans;
    }
};