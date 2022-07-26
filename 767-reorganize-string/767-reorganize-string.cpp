class Solution
{
    public:
        string reorganizeString(string s)
        {
            unordered_map<char, int> hashMap;
            for (auto ch: s)
                hashMap[ch]++;
            priority_queue<pair<int, char>> maxHeap;
            for (auto it: hashMap)
                maxHeap.push({ it.second,
                    it.first });
            string ans;

            while (maxHeap.size() >= 2)
            {
                auto top1 = maxHeap.top();
                maxHeap.pop();
                ans += top1.second;
                auto top2 = maxHeap.top();
                maxHeap.pop();
                ans += top2.second;
                top2.first--;

                if (top2.first > 0)
                    maxHeap.push({ top2.first,
                        top2.second });

                top1.first--;
                if (top1.first > 0)
                    maxHeap.push({ top1.first,
                        top1.second });
            }

            while (!maxHeap.empty())
            {
                auto top = maxHeap.top();
                maxHeap.pop();
                if (top.first > 1)
                    return "";
                ans += top.second;
            }

            return ans;
        }
};