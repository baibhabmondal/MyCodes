/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

class Solution
{
  public:
    unordered_map<string, int> m;

    int minPathSum(vector<vector<int>> &grid)
    {
        int row = grid.size() - 1, col = grid[0].size() - 1;
        return solve(row, col, grid);
    }

    int solve(int i, int j, vector<vector<int>> &grid)
    {
        if (i < 0 || j < 0)
            return INT_MAX;
        if (i == 0 && j == 0)
            return grid[i][j];

        string temp = "";
        temp += '0' + i;
        temp += ",";
        temp += '0' + j;

        if (m[temp])
            return m[temp];

        int ans = min(solve(i - 1, j, grid), solve(i, j - 1, grid)) + grid[i][j];
        // cout<<i<<","<<j<<":"<<ans<<endl;
        return m[temp] = ans;
    }
};