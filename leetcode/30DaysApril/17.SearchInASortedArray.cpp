/*

Search in Rotated Sorted Array

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

*/

class Solution
{
  public:
    int search(vector<int> &nums, int target)
    {
        int rot = index(nums);
        return bsearch(nums, rot, target);
        // return rot;
    }

    int bsearch(vector<int> &nums, int rot, int target)
    {
        int n = nums.size();
        int l = 0, r = n - 1;

        while (l <= r)
        {

            int mid = (l + r) / 2;
            int tmid = (mid + rot) % n;
            cout << mid << "," << tmid << endl;
            if (nums[tmid] == target)
            {
                return tmid;
            }
            else if (nums[tmid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return -1;
    }

    int index(vector<int> &nums)
    {

        if (nums.size() <= 1 || nums[0] < nums[nums.size() - 1])
            return 0;
        if (nums.size() == 2)
        {
            if (nums[0] < nums[1])
                return 0;
            else
                return 1;
        }
        int l = 0, r = nums.size() - 1;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            cout << mid << '\n';
            if (nums[mid] > nums[mid + 1])
                return mid + 1;
            if (nums[mid - 1] > nums[mid])
                return mid;
            if (nums[mid] > nums[0])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return 0;
    }
};