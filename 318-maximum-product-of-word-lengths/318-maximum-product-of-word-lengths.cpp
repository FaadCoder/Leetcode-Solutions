class Solution
{

    int getWordMask(string & word)
    {
        int wordMask = 0;

        for (char ch: word)
        {
            wordMask |= (1 << (ch - 'a'));
        }

        return wordMask;
    }

    vector<int> maskWords(vector<string> &words)
    {
        int numberOfWords = words.size();
        vector<int> maskArray(numberOfWords, 0);
        int idx = 0;
        for (string word: words)
        {
            maskArray[idx] = getWordMask(word);
            idx += 1;
        }

        return maskArray;
    }

    int calculateMaxProduct(vector<int> charMaskArray, vector<string> &words)
    {
        int numberOfWords = words.size();
        int maxProduct = 0;
        for (int outerIdx = 0; outerIdx < numberOfWords; outerIdx++)
        {
            for (int innerIdx = outerIdx + 1; innerIdx < numberOfWords; innerIdx++)
            {
                if (!(charMaskArray[outerIdx] &charMaskArray[innerIdx]))
                {
                    maxProduct = max(maxProduct, (int) words[outerIdx].length() *(int) words[innerIdx].length());
                }
            }
        }
        return maxProduct;
    }

    public:
        int maxProduct(vector<string> &words)
        {
            int numberOfWords = words.size();
            vector<int> charMaskArray = maskWords(words);
            int maxProductAns = calculateMaxProduct(charMaskArray, words);
            return maxProductAns;
        }
};