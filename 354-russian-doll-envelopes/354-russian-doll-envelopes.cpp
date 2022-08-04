class Solution 
{
    
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(begin(envelopes),end(envelopes),[&](vector<int> &a,vector<int> &b){
            return a[0]==b[0]?a[1]>b[1]:a[0]<b[0];
        });
        
        int n = envelopes.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            int currHeight = envelopes[i][1];
            auto it = lower_bound(ans.begin(),ans.end(),currHeight);
            
            if(it==ans.end())
                ans.push_back(currHeight);
            else
            {
                *it = currHeight;
            }
        }
        
        return ans.size();
    }
};