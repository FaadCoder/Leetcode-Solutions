class Vector2D {
    int row = 0;
    int col = 0;
    vector<vector<int>> vec;
public:
    Vector2D(vector<vector<int>>& vec) {
        this->vec = vec;
        row = 0;
        col = 0;
    }
    
    int next() {
        hasNext();
        return vec[row][col++];
    }
    
    bool hasNext() {
        while(row<vec.size() and vec[row].size()==col)
            row++,col=0;
        
        return (row<vec.size());
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */