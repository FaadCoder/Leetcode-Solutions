class Solution
{

    bool isAlphanumeric(char ch)
    {
        return ((ch >= 'A' and ch <= 'Z') 
                or (ch >= 'a' and ch <= 'z') 
                or (ch >= '0' and ch <= '9'));
    }

    public:
        bool isPalindrome(string s)
        {
            int startPtr = 0;
            int endPtr = s.length() - 1;
            while (startPtr < endPtr)
            {
                char charAtStartPtr = s[startPtr];
                char charAtEndPtr = s[endPtr];

                bool isCharAtStartPtrAlphanumeric = isAlphanumeric(charAtStartPtr);
                bool isCharAtEndtPtrAlphanumeric = isAlphanumeric(charAtEndPtr);

                if (isCharAtStartPtrAlphanumeric and isCharAtEndtPtrAlphanumeric)
                {
                    if (tolower(charAtStartPtr) != tolower(charAtEndPtr))
                        return false;
                    startPtr += 1;
                    endPtr -= 1;
                }
                else if (!isCharAtStartPtrAlphanumeric)
                    startPtr += 1;
                else
                    endPtr -= 1;
            }
            return true;
        }
};