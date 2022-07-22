class Solution
{
    public:
        int longestValidParentheses(string s)
        {
            int left = 0, right = 0;
            int maxLength = 0;
            for (char &ch: s)
            {
                if (ch == '(')
                {
                    left++;
                }
                else
                {
                    right++;
                }
                if (right > left)
                    left = 0, right = 0;
                if (left == right)
                    maxLength = max(maxLength, left + right);
            }
            
            left = 0,right = 0;
            
            for (int idx = s.length() - 1; idx >= 0; idx--)
            {
                char ch = s[idx];
                if (ch == '(')
                {
                    left++;
                }
                else
                {
                    right++;
                }
                if (right < left)
                    left = 0, right = 0;
                if (left == right)
                    maxLength = max(maxLength, left + right);
            }

            return maxLength;
        }
};