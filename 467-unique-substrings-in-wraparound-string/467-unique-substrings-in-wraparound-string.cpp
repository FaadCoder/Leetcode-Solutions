class Solution
{
    vector<int> count;

    void initializeCountVector()
    {
        cout.clear();
        count.resize(26, 0);
    }

    bool areLettersContiguous(char a, char b)
    {
        return ((a - b) == 1 or(b - a) == 25);
    }

    void populateSubstringsCount(string & str)
    {
        int maxContiguousLength = 0;
        int stringSize = str.length();
        for (int idx = 0; idx < stringSize; idx++)
        {
            if (idx > 0 and areLettersContiguous(str[idx], str[idx - 1]))
            {
                maxContiguousLength += 1;
            }
            else
            {
                maxContiguousLength = 1;
            }
            count[str[idx] - 'a'] = max(count[str[idx] - 'a'], maxContiguousLength);
        }
    }

    int computeSum()
    {
        return accumulate(count.begin(), count.end(), 0);
    }

    public:
        int findSubstringInWraproundString(string p)
        {
            initializeCountVector();
            populateSubstringsCount(p);
            return computeSum();
        }
};