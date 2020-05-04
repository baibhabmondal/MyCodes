/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/

class Solution
{
  public:
    unordered_set<string> visited;
    int numIslands(vector<vector<char>> &grid)
    {
        int i = 0, j = 0;
        int count = 0;
        for (i = 0; i < grid.size(); i++)
        {
            for (j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '0')
                    continue;
                string temp = "";
                temp += '0' + i;
                temp += ",";
                temp += '0' + j;
                if (visited.find(temp) == visited.end())
                {
                    solve(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }

    void solve(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
        {
            return;
        }
        string temp = "";
        temp += '0' + i;
        temp += ",";
        temp += '0' + j;
        if (grid[i][j] == '0')
        {
            visited.insert(temp);
            return;
        }
        if (visited.find(temp) != visited.end())
            return;
        // cout<<temp<<'\n';
        visited.insert(temp);
        solve(grid, i, j + 1);
        solve(grid, i + 1, j);
        solve(grid, i, j - 1);
        solve(grid, i - 1, j);
        // visited.insert(temp);
    }
};
