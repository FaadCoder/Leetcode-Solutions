class Solution {
public:
    
    // for calculating the soldier using binary search
    int binary(vector<int> m)
    {
        int l = 0;
        int h = m.size()-1;
        while(l <= h)
        {
            int mid = l + (h-l)/2;
            if(m[mid] == 0)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        // a binary heap which will maintain pair of count and index {count,index}
        priority_queue<pair<int,int> > pq;
        vector<int> ans;
        for(int i = 0; i<mat.size(); ++i)
        {
            // calularing cnt of soldier
            int cnt = binary(mat[i]);
			
			// instead  of using binary func for calculating cnt of 1
			// we can use this stl count function
			// int cnt = count(mat[i].begin(),mat[i].end(),1);
			
            pq.push(make_pair(cnt,i));
            
            // we need to maintain top k smallest elements
            if(pq.size() > k)
                pq.pop();
        }
        
        // making answer vector
        for(int i = 0; i<k; ++i)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
	// for github repository link go to my profile.
};