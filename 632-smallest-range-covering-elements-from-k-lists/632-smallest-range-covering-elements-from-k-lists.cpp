struct ListDetail{
    int listIndex;
    int elementIndex;
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int lists = nums.size();
        
        auto comparator = [&](ListDetail &list1, ListDetail &list2){
            return nums[list1.listIndex][list1.elementIndex] > nums[list2.listIndex][list2.elementIndex];
        };
        
        priority_queue<ListDetail, vector<ListDetail>, decltype(comparator)> minHeap(comparator);
        
        int high = INT_MIN;
        int low = INT_MAX;
        
        for(int list = 0; list < lists; list++)
        {
            int element = nums[list][0];
            high = max(high, element);
            low = min(low, element);
            minHeap.push(ListDetail{list, 0});
        }
        
        vector<int> range = {low, high};        
        
        while(!minHeap.empty())
        {
            ListDetail currentListDetail = minHeap.top();
            minHeap.pop();
            
            int listIndex = currentListDetail.listIndex;
            int elementIndex = currentListDetail.elementIndex;
            int element = nums[listIndex][elementIndex];
            
            if(range[1] - range[0] > high - element)
            {
                range[0] = element;
                range[1] = high;
                
            }
            
            if(elementIndex + 1 == nums[listIndex].size())
                break;
            
            high = max(high, nums[listIndex][elementIndex + 1]);
            
            minHeap.push(ListDetail{listIndex, elementIndex + 1});
        }
        
        return range;
    }
};