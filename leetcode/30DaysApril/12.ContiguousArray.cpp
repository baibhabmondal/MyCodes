/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.

*/

class Solution
{
  public:
    int findMaxLength(vector<int> &nums)
    {
        int n = 2 * nums.size() + 1;
        vector<int> arr(n, -2);
        // int arr[n] = {-2};
        arr[nums.size()] = -1;
        int maxlen = 0, count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            count = count + (nums[i] == 0 ? -1 : 1);
            if (arr[count + nums.size()] >= -1)
            {
                maxlen = max(maxlen, i - arr[count + nums.size()]);
            }
            else
            {
                arr[count + nums.size()] = i;
            }
        }
        return maxlen;
    }
};