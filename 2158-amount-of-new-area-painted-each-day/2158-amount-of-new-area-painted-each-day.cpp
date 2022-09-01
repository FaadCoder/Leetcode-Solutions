class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paints) {
        unordered_map<int, int> last;
        vector<int> areaPainted;
        
        int idx = 0;
        
        for(auto paint : paints)
        {
            int start = paint[0];
            int end = paint[1];
            int areaCovered = 0;
            while(start < end)
            {
                int jump = max(start + 1, last[start]);
                areaCovered += (last[start] == 0);
                last[start] = max(last[start], end);
                start = jump;
            }
            
            areaPainted.push_back(areaCovered);
  
        }
        
        return areaPainted;
    }
};