/*
WritGiven an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

*/


class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        
        // kadane's algorithm
        
        int n = nums.size();
        if(n == 0)
            return 0;
        if(n == 1)
            return nums[0];
        int local_sum = nums[0];
        int maxSum = nums[0], i = 0;
        
        for(i=1; i<n; i++) {
            local_sum = max(local_sum + nums[i], nums[i] );
            if(maxSum < local_sum) {
                maxSum = local_sum;
            }
        }
        return maxSum;
    }
};
