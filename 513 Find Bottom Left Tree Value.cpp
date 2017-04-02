/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    struct node {
      TreeNode* n;
      int dep;
    };
public:
    int findBottomLeftValue(TreeNode* root) {
        int min_dep = 0, ans = root->val;
        queue<node> q;
        q.push(node{root, 0});
        while(!q.empty()) {
            node cur = q.front();
            q.pop();
            if(cur.dep > min_dep) {
                ans = cur.n->val;
                min_dep = cur.dep;
            } 
            if(cur.n->left != NULL) {
                q.push(node{cur.n->left, cur.dep + 1});
            }
            if(cur.n->right != NULL) {
                q.push(node{cur.n->right, cur.dep + 1});
            }
        }
        return ans;
    }
};
