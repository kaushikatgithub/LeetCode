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
public:
    void inorder(TreeNode* root, vector<int> &bst) {
        if(root == NULL) return;
        if(!root->left && !root->right)
            bst.push_back(root->val);
        inorder(root->left, bst);
        inorder(root->right, bst);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> bst1, bst2;
        inorder(root1, bst1);
        inorder(root2, bst2);

        if(bst1.size() != bst2.size()) {
            return false;
        }
        int i=0, n = bst1.size();
        while(i<n) {
            if(bst1[i] != bst2[i]) {
                return false;
            }
            i++;
        }
        return true;
    }
};
