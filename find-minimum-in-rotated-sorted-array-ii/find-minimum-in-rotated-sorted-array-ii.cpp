class Solution {
public:
    int findMin(vector<int> &num) {
        int l = 0,r = num.size() - 1,mid = 0;
        while(l < r) {
            mid = l + (r - l) / 2;           
            if (num[mid] > num[r]) l = mid + 1;
            else if (num[mid] < num[r]) r = mid;
            else r--;
        }
        return num[l];
    }
};