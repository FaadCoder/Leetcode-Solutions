class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> ans;
        auto it = lower_bound(nums.begin(),nums.end(),target);
        if(it==nums.end() or *it!=target)
        {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(it-nums.begin());
            auto it2 = upper_bound(nums.begin(),nums.end(),target);
            if(it2==nums.begin())
            {
                ans.push_back(-1);
            }
            else
            {
                --it2;
                if(*it2==target)
                    ans.push_back(it2-nums.begin());
                else
                    ans.push_back(-1);
            }
        }
        return ans;
    }
};