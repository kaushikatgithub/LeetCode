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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) {
            return {};
        }
        vector<vector<int>> ans;
        deque<TreeNode*> q;
        q.push_back(root);
        bool ltor = true;
        while(!q.empty()) {
            int sz = q.size();
            vector<int> level;
            while(sz--) {
                TreeNode* node = NULL;
                if(ltor) {
                    node = q.front();
                    q.pop_front();
                }else {
                    node = q.back();
                    q.pop_back();
                }
                level.push_back(node->val);

                if(ltor) {
                    if(node->left) {
                        q.push_back(node->left);
                    }
                    if(node->right) {
                        q.push_back(node->right);
                    }
                }else {
                    if(node->right) {
                        q.push_front(node->right);
                    }
                    if(node->left) {
                        q.push_front(node->left);
                    }
                }
                
            }
            ltor = !ltor;
            ans.push_back(level);
        }
        return ans;
    }
};
