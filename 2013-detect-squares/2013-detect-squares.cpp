class DetectSquares {
    map<pair<int,int>,int> pointsFreqMap;
    vector<pair<int,int>> points;
    
    bool isDiagonalPoint(int x1,int y1,int x2,int y2)
    {
       return (abs(x1-x2)==abs(y1-y2));   
    }

public:
    DetectSquares() {
        pointsFreqMap.clear();
        points.clear();
    }
    
    void add(vector<int> point) {
        pointsFreqMap[{point[0],point[1]}]++;
        points.push_back({point[0],point[1]});
    }
    
    int count(vector<int> point) {
        int res = 0;
        int px = point[0];
        int py = point[1];
        // Fix diagonal point.
        for(auto pt:points)
        {
            int x = pt.first;
            int y = pt.second;
            if(px==x or py==y or !isDiagonalPoint(px,py,x,y))
                continue;
            res += pointsFreqMap[{x,py}] * pointsFreqMap[{px,y}];
        }
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */