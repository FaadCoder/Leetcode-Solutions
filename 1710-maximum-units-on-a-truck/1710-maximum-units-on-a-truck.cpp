class Solution
{
    public:
        int maximumUnits(vector<vector < int>> &boxTypes, int truckSize)
        {
            auto comparatorFunction =[& ](vector<int> &boxType1, vector<int> &boxType2)
            {
                int numberOfUnitsPerBoxOfType1 = boxType1[1];
                int numberOfUnitsPerBoxOfType2 = boxType2[1];

                return (numberOfUnitsPerBoxOfType1 > numberOfUnitsPerBoxOfType2);
            };

            sort(boxTypes.begin(), boxTypes.end(), comparatorFunction);

            int maxUnits = 0;

            for (vector<int> &boxType: boxTypes)
            {
                int boxesToTake = min(truckSize, boxType[0]);
                if (boxesToTake <= 0)
                    break;
                maxUnits += boxesToTake *boxType[1];
                truckSize -= boxesToTake;
            }

            return maxUnits;
        }
};