/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution
{
    int maxDepth = 1;
    int sumOfIntegers = 0;
    
    int getSum(vector<NestedInteger> &nestedList, int level=1)
    {
        if(nestedList.empty())
            return 0;
        int sum = 0;
        maxDepth = max(maxDepth,level);
        for(NestedInteger &nestedInteger:nestedList)
        {
            if(nestedInteger.isInteger())
            {
                maxDepth = max(maxDepth,level);
                sum+=(level*nestedInteger.getInteger());
                sumOfIntegers += nestedInteger.getInteger();
            }
            else
                sum+=getSum(nestedInteger.getList(),level+1);

        }
        return sum;
    }

    public:
        int depthSumInverse(vector<NestedInteger> &nestedList)
        {
            int weightedSum = getSum(nestedList);
            return (maxDepth+1)*(sumOfIntegers)-weightedSum;
        }
};