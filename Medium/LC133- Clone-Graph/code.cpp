/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* dfs(Node* node) {

        Node* copy = new Node(node->val);
        mp[node] = copy;
        
        for(auto nd : node->neighbors) {
            
            if(mp.find(nd) != mp.end()) {
                copy->neighbors.push_back(mp[nd]);
            }else {
                copy->neighbors.push_back(dfs(nd));
            }

        }
        return copy;
    }
    Node* cloneGraph(Node* node) {

        if(node == NULL) {
            return NULL;
        }
        return dfs(node);
    }
};
