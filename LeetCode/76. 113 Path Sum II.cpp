// Q:

// Comments

// Initial Instinct

// Solution Code
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
public:
    void helper(TreeNode *root, int targetSum, vector<int> v, vector<vector<int>> &ans)
    {
        if (root == NULL)
            return;
        v.push_back(root->val);
        if (targetSum == root->val and (root->left == NULL and root->right == NULL))
        {
            ans.push_back(v);
            return;
        }
        helper(root->left, targetSum - root->val, v, ans);
        helper(root->right, targetSum - root->val, v, ans);
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> v;
        helper(root, targetSum, v, ans);
        return ans;
    }
};

// Optimised solution

// FeedBack and more