class Solution {
public:
    int maxArea(vector<int>& height) {
        int st=0,en=height.size()-1;
        int mx=0;
        while(st<en)
        {
            mx=max(mx,(en-st)*min(height[st],height[en]));
            if(height[st]<height[en])
                st++;
            else
                en--;
        }
        return mx;
    }
};