// Given a non-empty binary tree, find the maximum path sum.

// For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

// Example 1:

// Input: [1,2,3]

//        1
//       / \
//      2   3

// Output: 6
// Example 2:

// Input: [-10,9,20,null,null,15,7]

//    -10
//    / \
//   9  20
//     /  \
//    15   7

// Output: 42

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    int ans;

  public:
    int maxPathSum(TreeNode *root)
    {
        ans = root->val;
        dfs(root);
        return ans;
    }

    void dfs(TreeNode *root)
    {
        if (!root)
            return;

        dfs(root->left);
        dfs(root->right);

        cout << root->val << "=>";
        if (root->left != NULL && root->right != NULL)
        {
            int lpath = max(root->left->val, root->val + root->left->val);
            int rpath = max(root->right->val, root->val + root->right->val);
            int lrpath = max(root->val + root->left->val + root->right->val, root->val);
            ans = max(ans, max(lpath, max(rpath, lrpath)));
            int temp = root->val;
            root->val = max(root->val, root->val + root->left->val);
            root->val = max(root->val, temp + root->right->val);
            cout << root->val << endl;
            return;
        }

        if (root->left != NULL)
        {
            int lpath = max(root->left->val, root->val + root->left->val);
            int path = max(lpath, root->val);
            ans = max(ans, path);
            root->val = max(root->val, root->val + root->left->val);
            cout << root->val << endl;
            return;
        }
        if (root->right != NULL)
        {
            int rpath = max(root->right->val, root->val + root->right->val);
            int path = max(rpath, root->val);
            ans = max(ans, path);
            root->val = max(root->val, root->val + root->right->val);
            cout << root->val << endl;
            return;
        }
        cout << root->val << endl;
        ans = max(ans, root->val);
    }
};