// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

// Example:

// Input: 

// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0

// Output: 4

class Solution
{
  public:
    int maximalSquare(vector<vector<char>> &mat)
    {

        int i = 0, j = 0, row = mat.size();
        if (row == 0)
            return 0;
        int col = mat[0].size();
        if (col == 0)
            return 0;
        int ans = 0;
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                if (mat[i][j] == '1')
                {
                    int itr = 1;
                    while (check(i, j, ++itr, mat))
                        ;
                    itr--;
                    ans = max(itr * itr, ans);
                }
            }
        }
        return ans;
    }

    bool check(int i, int j, int n, vector<vector<char>> &mat)
    {
        if (i + n > mat.size() || j + n > mat[0].size())
            return false;
        int row = i + n, col = j + n;
        while (i < row)
        {
            if (mat[i][col - 1] != '1')
                return false;
            i++;
        }

        while (j < col)
        {
            if (mat[row - 1][j] != '1')
                return false;
            j++;
        }

        return true;
    }
};