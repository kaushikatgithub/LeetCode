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
class Solution {
private:
    int height(TreeNode* root) {
    if(root == NULL)
        return 0;
    else
        return 1 + max(height(root->left),height(root->right));
}
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int curr_dia = height(root->left) + height(root->right);
        int left_subtree_dia = diameterOfBinaryTree(root->left);
        int right_subtree_dia = diameterOfBinaryTree(root->right);
        int mx = max(left_subtree_dia,right_subtree_dia);
        return max(curr_dia,mx);
    }
};
