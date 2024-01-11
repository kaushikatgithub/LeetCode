/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxDifference(TreeNode* root, int maxi, int mini) {
        if (root == NULL) {
            return (maxi - mini);
        }
        maxi = max(maxi, root->val);
        mini = min(mini, root->val);
        return max(maxDifference(root->left, maxi, mini), maxDifference(root->right, maxi, mini));
    }
    int maxAncestorDiff(TreeNode* root) {
        return maxDifference(root, root->val, root->val);
    }
};
