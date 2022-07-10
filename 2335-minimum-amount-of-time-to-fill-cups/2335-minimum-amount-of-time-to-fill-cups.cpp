class Solution
{
    public:
        int fillCups(vector<int> &amount)
        {
            int minTime = 0;
            priority_queue<int> minHeap;
            for (int ele: amount)
            {
                if (ele != 0)
                    minHeap.push(ele);
            }

            while (!minHeap.empty())
            {
                int ele1 = minHeap.top();
                minHeap.pop();
                int ele2 = -1;
                if (!minHeap.empty())
                {
                    ele2 = minHeap.top();
                    minHeap.pop();
                }
                ele1 -= 1;
                ele2 -= 1;
                if (ele1 > 0)
                {
                    minHeap.push(ele1);
                }
                if (ele2 > 0)
                {
                    minHeap.push(ele2);
                }
                minTime++;
            }

            return minTime;
        }
};