/*
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

Constraints:

1 <= preorder.length <= 100
1 <= preorder[i] <= 10^8
The values of preorder are distinct.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {

        int i = 0;
        TreeNode *root = NULL;
        for (i = 0; i < preorder.size(); i++)
        {
            root = insert(root, preorder[i]);
        }
        return root;
    }

    TreeNode *insert(TreeNode *root, int val)
    {
        TreeNode *nn = new TreeNode(val);
        if (!root)
        {
            root = nn;
            return root;
        }
        TreeNode *temp = root;
        TreeNode *prev = root;
        while (temp != NULL)
        {
            prev = temp;
            if (val < temp->val)
            {
                temp = temp->left;
            }
            else if (val > temp->val)
            {
                temp = temp->right;
            }
        }
        if (val < prev->val)
            prev->left = nn;
        else
            prev->right = nn;
        return root;
    }
};