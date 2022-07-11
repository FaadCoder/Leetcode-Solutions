/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution
{

    int getIndex(int low, int high, int target, const ArrayReader &reader)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int currentSecret = reader.get(mid);
            if (currentSecret == target)
                return mid;
            else if (currentSecret < target)
                low++;
            else
                high--;
        }
        return -1;
    }

    public:
        int search(const ArrayReader &reader, int target)
        {
            int low = 0, high = 1;
            while (reader.get(high) < target)
                high <<= 1;
            return getIndex(low, high, target, reader);
        }
};