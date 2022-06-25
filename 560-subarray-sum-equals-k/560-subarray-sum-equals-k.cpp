class Solution
{
    public:
        int subarraySum(vector<int> &nums, int k)
        {

            unordered_map<int, int> hashMap;
            int currentSum = 0;
            int subarrayCount = 0;
            hashMap[currentSum] = 1;

            for (int num: nums)
            {
                currentSum += num;
                if (hashMap.count(currentSum - k))
                    subarrayCount += hashMap[currentSum - k];
                hashMap[currentSum] += 1;
            }

            return subarrayCount;
        }
};