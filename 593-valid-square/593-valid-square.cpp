class Solution {
    int getDistanceBetweenPoints(vector<int> &point1,vector<int> &point2)
    {
        return (point1[0]-point2[0])*(point1[0]-point2[0]) + 
            (point1[1]-point2[1])*(point1[1]-point2[1]);
    }
    
    bool isSame(vector<int> &point1,vector<int> &point2)
    {
       return (point1[0]==point2[0]) and (point1[1]==point2[1]); 
    }
    
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        if(isSame(p1,p2) or isSame(p1,p3) or isSame(p1,p4) or isSame(p2,p3) or isSame(p2,p4) or isSame(p3,p4))
            return false;
        
        unordered_set<int> hashSet;
        hashSet.insert(getDistanceBetweenPoints(p1,p2));
        hashSet.insert(getDistanceBetweenPoints(p1,p3));
        hashSet.insert(getDistanceBetweenPoints(p1,p4));
        hashSet.insert(getDistanceBetweenPoints(p2,p3));
        hashSet.insert(getDistanceBetweenPoints(p2,p4));
        hashSet.insert(getDistanceBetweenPoints(p3,p4));
        
        return hashSet.size()==2;
    }
};