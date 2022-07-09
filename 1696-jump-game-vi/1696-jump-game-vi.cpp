class Solution
{
    public:
        int maxResult(vector<int> &nums, int k)
        {
            int numberOfElements = nums.size();
            deque<int> monotonicQueue;
            vector<int> costToReachEnd(numberOfElements);

            costToReachEnd[numberOfElements - 1] = nums.back();
            monotonicQueue.push_back(numberOfElements - 1);

            for (int elementIdx = numberOfElements - 2; elementIdx >= 0; elementIdx--)
            {
                if (!monotonicQueue.empty() and monotonicQueue.front() - elementIdx > k)
                    monotonicQueue.pop_front();

                costToReachEnd[elementIdx] = nums[elementIdx] + costToReachEnd[monotonicQueue.front()];
                while (!monotonicQueue.empty() and costToReachEnd[monotonicQueue.back()] < costToReachEnd[elementIdx])
                    monotonicQueue.pop_back();
                monotonicQueue.push_back(elementIdx);
            }
            return costToReachEnd[0];
        }
};