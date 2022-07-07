class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        vector<int> paintedArea(paint.size(),0);
        vector<int> paintTill(50001,0);
        int idx = 0;
        for(auto &paintRange:paint)
        {
            int start = paintRange[0];
            int end = paintRange[1];
            while(start<end)
            {
                int nextStart = max(start+1,paintTill[start]);
                if(paintTill[start]==0)
                    paintedArea[idx]++;
                paintTill[start] = max(paintTill[start],end);
                start = nextStart;
            }
            idx++;
        }
        return paintedArea;
    }
};