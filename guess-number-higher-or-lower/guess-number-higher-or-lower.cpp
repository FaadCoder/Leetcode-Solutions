/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l=1,h=n;
        while(l<=h)
        {
            int mid = (l+(h-l)/2);
            int guessed = guess(mid);
            if(guessed==1)
            {
                l = mid+1;
            }
            else if(guessed==-1)
            {
                h = mid-1;    
            }
            else
            {
                return mid;
            }
                
        }
        return -1;
    }
};