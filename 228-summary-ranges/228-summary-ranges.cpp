class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<string> ranges;
        if(nums.empty())
            return ranges;
        int i=0;
        while(i<nums.size())
        {
            int prev = nums[i];
            int j = i+1;
            string temp=to_string(prev);
            while(j<nums.size())
            {
                int curr = nums[j];
                if(curr!=prev+1)
                {
                    break;
                }
                prev = curr;
                j++;
            }
            if(prev!=nums[i])
            {
                temp+="->"+to_string(prev);
            }
            ranges.push_back(temp);
            i=j;
        }
        
        return ranges;
    }
};