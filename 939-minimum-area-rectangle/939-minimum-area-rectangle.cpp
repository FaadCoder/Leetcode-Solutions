class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int,unordered_set<int>> xToYCoordinatesHashMap;
        
        for(vector<int> &point:points)
        {
            int x = point[0];
            int y = point[1];
            xToYCoordinatesHashMap[x].insert(y);
        }
        
        int minAreaRectangle = INT_MAX;
        
        for(int point1=0;point1<size(points);point1++)
        {
            for(int point2=point1+1; point2<size(points);point2++)
            {
                int x1 = points[point1][0];
                int y1 = points[point1][1];
                int x2 = points[point2][0];
                int y2 = points[point2][1];
                if(x1==x2 or y1==y2)
                    continue;
                if(xToYCoordinatesHashMap[x1].count(y2) and xToYCoordinatesHashMap[x2].count(y1))
                    minAreaRectangle = min(minAreaRectangle,abs(x1-x2)*abs(y1-y2));
                
            }
        }
        
        return minAreaRectangle==INT_MAX?0:minAreaRectangle;
    }
};