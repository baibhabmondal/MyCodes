// Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

 

// Example 1:

// Input: 5
// Output: 2
// Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
 

// Example 2:

// Input: 1
// Output: 0
// Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 

// Note:

// The given integer is guaranteed to fit within the range of a 32-bit signed integer.
// You could assume no leading zero bit in the integer’s binary representation.
// This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/

class Solution
{
  public:
    int findComplement(int num)
    {
        string c = "";
        while (num)
        {
            c += ('0' + num % 2 == '0') ? '1' : '0';
            num /= 2;
        }
        int n = c.length(), ans = 0, i = 0;
        while (i < n)
        {
            if (c[i] == '1')
            {
                ans += pow(2, i);
            }
            ++i;
        }
        return ans;
    }
};