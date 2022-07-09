class Solution
{
    public:
        int wordsTyping(vector<string> &sentence, int rows, int cols)
        {
            string sentenceStringWithSpaces = "";
            for (string &word: sentence)
                sentenceStringWithSpaces += (word + " ");

            int combinedSentenceStringLength = sentenceStringWithSpaces.length();
            int cursor = 0;

            for (int row = 0; row < rows; row++)
            {
                cursor += cols;
                if (sentenceStringWithSpaces[cursor % combinedSentenceStringLength] == ' ')
                    cursor++;
                else
                {
                    while (cursor > 0 and sentenceStringWithSpaces[(cursor - 1) % combinedSentenceStringLength] != ' ')
                        cursor -= 1;
                }
            }

            return cursor / combinedSentenceStringLength;
        }
};