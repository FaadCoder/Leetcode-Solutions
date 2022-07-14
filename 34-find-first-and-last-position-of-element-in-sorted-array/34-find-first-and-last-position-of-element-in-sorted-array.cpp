class Solution
{
    public:
        int search(vector<int> &nums, int target, bool left)
        {
            int low = 0;
            int high = nums.size();

            while (low < high)
            {
                int mid = low + (high - low) / 2;

                if (target < nums[mid] || (left && nums[mid] == target))
                {
                    high = mid;
                }
                else
                {
                    low = mid + 1;
                }
            }

            return low;
        }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = search(nums, target, true);
        int right = search(nums, target, false);

        if (left == nums.size() || nums[left] != target)
            return { -1,
                -1 };
        return {
            left,
            right - 1
        };
    }
};