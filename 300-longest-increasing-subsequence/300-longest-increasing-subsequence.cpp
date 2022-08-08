class Solution
{
    vector<vector<int>> topDownDP;
    private:
        // 1. TOP DOWN DP Solution  
        int lengthOfLISTopDown(vector<int> &nums,int idx, int prev)
        {
            if(idx==nums.size())
                return 0;
            
            if(topDownDP[idx][prev+10001]!=-1)
                return topDownDP[idx][prev+10001];
            
            
            int excludeCurrentElement = lengthOfLISTopDown(nums,idx+1,prev);
            int includeCurrentElement = 0;
            if(nums[idx]>prev)
                includeCurrentElement = 1+lengthOfLISTopDown(nums,idx+1,nums[idx]);
            
                return topDownDP[idx][prev+10001] = max(excludeCurrentElement, includeCurrentElement);
        }
    
    
        // 2. Bottom UP DP Solution
        int lengthOfLISBottomUP(vector<int> &nums)
        {
            int elements = nums.size();
            vector<int> lisEndingAtIndex(elements,1);
            
            for(int currIdx = 1; currIdx<elements; currIdx++)
            {
                int currElement = nums[currIdx];
                for(int prevIdx = 0; prevIdx<currIdx; prevIdx++)
                {
                    int prevElement = nums[prevIdx];
                    if(currElement > prevElement and lisEndingAtIndex[currIdx] < lisEndingAtIndex[prevIdx] + 1)
                    {
                        lisEndingAtIndex[currIdx] = lisEndingAtIndex[prevIdx] + 1;
                    }
                }
            }
            
            return *max_element(lisEndingAtIndex.begin(),lisEndingAtIndex.end());
            
        }
        
    
        // 3. Binary Search Solution
        int lengthOfLISBinarySearch(vector<int> &nums)
        {
            vector<int> monotonicVector;

            for (int num: nums)
            {
                auto it = lower_bound(begin(monotonicVector), end(monotonicVector), num);
                if (it == monotonicVector.end())
                {
                    monotonicVector.push_back(num);
                }
                else
                {
                    *it = num;
                }
            }

            return (int) monotonicVector.size();
        }
        
    public:
        int lengthOfLIS(vector<int> &nums)
        {
            /*
            1. TOP DOWN DP
            topDownDP.resize(nums.size()+1,vector<int>(20004,-1));
            return lengthOfLISTopDown(nums,0,-10001);
            */
            
            
            //2. Bottom UP DP
                return lengthOfLISBottomUP(nums);
            
            
            // 3. Binary Search Solution
            // return lengthOfLISBinarySearch(nums);
        }
};