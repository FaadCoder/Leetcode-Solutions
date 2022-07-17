/*
Algorithm
- concentrate on first half
- Find the next permutation of first half
- Take care of odd and even length string
- Palindrome string  = Next Permutation of first half + Mid character + reverse(Next Permutation of first half)

*/

class Solution
{
    public:
        string nextPalindrome(string num)
        {
            string mid = string(num.length() % 2, num[num.length() / 2]);
            string firstHalf = num.substr(0, num.length() / 2);
            if (!next_permutation(begin(firstHalf), end(firstHalf)))
                return "";

            return firstHalf + mid + string(firstHalf.rbegin(), firstHalf.rend());
        }
};