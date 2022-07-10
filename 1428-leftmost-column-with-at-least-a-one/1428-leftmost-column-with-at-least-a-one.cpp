/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution
{

    int getPositionOfOne(BinaryMatrix &binaryMatrix, int row, int low, int high)
    {
        int ans = INT_MAX;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int valueAtMid = binaryMatrix.get(row, mid);
            if (valueAtMid == 1)
            {
                ans = mid;
                high = mid - 1;
            }
            else if (valueAtMid == 0)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }

    public:
        int leftMostColumnWithOne(BinaryMatrix & binaryMatrix)
        {
            int leftMostColumn = INT_MAX;

            auto dimensions = binaryMatrix.dimensions();
            int rows = dimensions[0];
            int cols = dimensions[1];

            for (int row = 0; row < rows; row++)
            {
                int positionOfOne = getPositionOfOne(binaryMatrix, row, 0, cols - 1);
                leftMostColumn = min(leftMostColumn, positionOfOne);
            }

            return leftMostColumn == INT_MAX ? -1 : leftMostColumn;
        }
};