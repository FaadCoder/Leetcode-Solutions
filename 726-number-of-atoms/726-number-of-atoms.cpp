class Solution
{
    public:
        string countOfAtoms(string formula)
        {
            if (formula.empty())
                return "";
            reverse(begin(formula), end(formula));

            map<string, int> elementFrequencyMap;
            stack<int> multiplyFactorStack;
            multiplyFactorStack.push(1);

            string currentElement = "";
            int multiplyFactor = 1;

            int idx = 0;
            while (idx < formula.length())
            {
                char currentChar = formula[idx];
                if (isdigit(currentChar))
                {
                    string val;
                    while (isdigit(formula[idx]))
                    {
                        val.push_back(formula[idx]);
                        idx++;
                    }
                    reverse(val.begin(), val.end());
                    multiplyFactor = stoi(val);
                    idx -= 1;
                }
                else if (currentChar == ')')
                {
                    multiplyFactorStack.push(multiplyFactor *multiplyFactorStack.top());
                    multiplyFactor = 1;
                }
                else if (currentChar >= 'a'
                    and currentChar <= 'z')
                {
                    currentElement.push_back(currentChar);
                }
                else if (currentChar >= 'A'
                    and currentChar <= 'Z')
                {
                    currentElement.push_back(currentChar);
                    reverse(begin(currentElement), end(currentElement));
                    elementFrequencyMap[currentElement] += multiplyFactor *multiplyFactorStack.top();
                    multiplyFactor = 1;
                    currentElement = "";
                }
                else
                {
                    multiplyFactorStack.pop();
                }
                idx++;
            }

            string resultingString;

            for (auto &it: elementFrequencyMap)
            {
                resultingString += it.first;
                if (it.second > 1)
                    resultingString += to_string(it.second);
            }
            return resultingString;
        }
};