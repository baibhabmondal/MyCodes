/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

*/

class Solution
{
  public:
    int subarraySum(vector<int> &nums, int k)
    {

        int i = 0, j = 0, n = nums.size();
        int count = 0;
        for (i = 0; i < n; i++)
        {
            int sum = nums[i];
            if (sum == k)
                count++;
            for (j = i + 1; j < n; j++)
            {
                // cout<<i<<" "<<sum<<endl;
                sum += nums[j];
                if (sum == k)
                {
                    count++;
                }
            }
        }
        return count;
    }
};