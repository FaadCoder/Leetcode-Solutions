class Solution
{
    public:
        vector<int> frequencySort(vector<int> &nums)
        {

            int count[202] = { 0 };
            for (int num: nums)
                count[num + 100]++;

            sort(begin(nums), end(nums), [& ](int a, int b)
            {
                return count[a + 100] == count[b + 100] ? a > b : count[a + 100] < count[b + 100];
	        });
            return nums;
        }
};