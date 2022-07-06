class Solution
{
    public:
        string findReplaceString(string S, vector<int> &indexes, vector<string> &sources, vector< string > &targets)
        {
            unordered_map<int, pair<int, string>> m;
            for (int i = 0; i < indexes.size(); i++)
                if (S.substr(indexes[i], sources[i].size()) == sources[i])
                    m[indexes[i]] = make_pair(sources[i].size(), targets[i]);
            string ans = "";
            for (int i = 0; i < S.size(); i++)
            {
                if (m.find(i) != m.end())
                {
                    ans += m[i].second;
                    i = i + m[i].first - 1;
                }
                else
                    ans += S[i];
            }
            return ans;
        }
};