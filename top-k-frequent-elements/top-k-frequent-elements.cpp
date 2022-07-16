/*
# Algorithm:

- calculate frequency of all elements
- Max frequency of any element can be equal to Size of array.
- Divide the elements into the frequency buckets.
- Start traversing the buckets from higher frequency to lower frequency.
- Parallely store the result and return it when result size equals to k

*/
class Solution
{

    public:
        vector<int> topKFrequent(vector<int> &nums, int k)
        {
            unordered_map<int, int> frequencyMap;

            for (int &num: nums)
                frequencyMap[num]++;

            vector<int> frequencyBuckets[nums.size() + 1];

            for (auto &it: frequencyMap)
                frequencyBuckets[it.second].push_back(it.first);

            vector<int> topKFrequentElements;

            for (int bucketIdx = nums.size(); bucketIdx >= 1; bucketIdx--)
            {
                for (int &element: frequencyBuckets[bucketIdx])
                {
                    topKFrequentElements.push_back(element);
                    if (topKFrequentElements.size() == k)
                        return topKFrequentElements;
                }
            }

            return topKFrequentElements;
        }
};