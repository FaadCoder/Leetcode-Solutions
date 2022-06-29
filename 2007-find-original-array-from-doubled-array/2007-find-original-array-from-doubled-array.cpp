class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int numberOfElements = changed.size();
        sort(changed.begin(),changed.end());
        vector<int> ans;
        
        for(int idx=0; idx<changed.size(); idx++)
        {
            int twice = (changed[idx] * 2);
            if(changed[idx] < 0)
                continue;
            
            auto it = lower_bound(begin(changed)+idx+1,end(changed),twice);
            
            if(it!=end(changed) and (*it) == twice)
            {
                *it = -1;
                ans.push_back(changed[idx]);
            }
            else
            {
                return {};   
            }
        }
        return ans;
    }
};
