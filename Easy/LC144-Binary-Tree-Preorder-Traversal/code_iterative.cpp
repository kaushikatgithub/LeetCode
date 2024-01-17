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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) {
            return {};
        }

        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* node = root;
        while(1) {
            
            if(node != NULL) {
                ans.push_back(node->val);
                st.push(node);
                node = node->left;
            }else {
                if(st.empty()) break;
                node = st.top();
                st.pop();
                node = node->right;
            }
        } 
        return ans;
    }
};
