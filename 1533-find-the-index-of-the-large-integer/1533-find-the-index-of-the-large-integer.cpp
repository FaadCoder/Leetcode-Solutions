/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int low = 0,high = reader.length()-1;
        
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int currentLen = high-low+1;
            int compareRanges = 0;
            if(currentLen & 1)
                compareRanges = reader.compareSub(low,mid,mid,high);
            else
                compareRanges = reader.compareSub(low,mid,mid+1,high);

            if(compareRanges==1)
            {
                high = mid;
            }
            else if(compareRanges==-1)
            {
                low = mid+1;
            }
            else
            {
                return mid;
            }
        }
        return low;
    }
};