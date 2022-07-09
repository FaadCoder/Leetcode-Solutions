class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ans;
        for(int ele:arr1)
        {
            auto it1 = lower_bound(begin(arr2),end(arr2),ele);
            auto it2 = lower_bound(begin(arr3),end(arr3),ele);
            if(it1!=arr2.end() and *it1==ele and it2!=arr3.end() and *it2==ele)
                ans.push_back(ele);
        }
        
        return ans;
    }
};