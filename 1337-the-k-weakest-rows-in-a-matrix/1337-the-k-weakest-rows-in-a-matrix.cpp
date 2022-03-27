class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        priority_queue<pair<int,int>> pq;
        int mx = mat[0].size();
        for(int i=0;i<mat.size();i++)
        {
            int sum=0;
            for(int j=0;j<mx;j++)
            {
                sum+=mat[i][j];
            }
            pq.push({sum,i});
            if(pq.size()>k)
                pq.pop();
        }
        vector<int> res;
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};