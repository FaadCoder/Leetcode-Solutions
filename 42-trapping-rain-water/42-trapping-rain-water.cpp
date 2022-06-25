class Solution {
public:
    int trap(vector<int>& height) {
        int leftPtr = 0;
        int rightPtr = height.size()-1;
        int maxHeightInLeft = 0;
        int maxHeightInRight = 0;
        int totalWaterTrapped = 0;
        
        while(leftPtr < rightPtr)
        {
            if(height[leftPtr] < height[rightPtr])
            {
                if(height[leftPtr] >= maxHeightInLeft)
                    maxHeightInLeft = height[leftPtr];
                else
                    totalWaterTrapped += maxHeightInLeft - height[leftPtr];
                leftPtr += 1;
            }
            else
            {
                if(height[rightPtr] >= maxHeightInRight)
                    maxHeightInRight = height[rightPtr];
                else
                    totalWaterTrapped += maxHeightInRight - height[rightPtr];
                rightPtr -= 1;
            }
        }
        return totalWaterTrapped;
    }
};