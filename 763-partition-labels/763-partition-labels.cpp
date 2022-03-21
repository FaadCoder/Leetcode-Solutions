class Solution {
public:
vector<int> partitionSequence(vector<char> &sequence)
    {
        int size = (int)sequence.size();
        if (!size)
        {
            return {};
        }
        // HashMap to store the last index occurrence of a character.
        unordered_map<char, int> lastIndexMap;
        for (int idx = 0; idx < size; idx++)
        {
            lastIndexMap[sequence[idx]] = idx;
        }
        // A Vector to store the partition length of each partition.
        vector<int> partitionsLength;
        int left = 0;
        while (left < size)
        {
            char currentChar = sequence[left];
            int lastIdx = lastIndexMap[currentChar];
            int right = left;
            while (right <= lastIdx)
            {
                char currentCharAtRight = sequence[right];
                lastIdx = max(lastIdx, lastIndexMap[currentCharAtRight]);
                right++;
            }
            partitionsLength.push_back(right - left);
            left = lastIdx + 1;
        }
        return partitionsLength;
    }
    vector<int> partitionLabels(string s) {
        vector<char> list;
        for(auto &i:s)
            list.push_back(i);
        return partitionSequence(list);
    }
};