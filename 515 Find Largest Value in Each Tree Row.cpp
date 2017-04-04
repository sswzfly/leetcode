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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }
        queue<T> q;
        q.push(T{root, 1});
        int INT_MIN;
        while(!q.empty()) {
            T cur = q.front();
            q.pop();
            if(ans.size() < cur.dep) {
                ans.push_back(cur.node->val);
            }
            else {
                if(ans.back() < cur.node->val) {
                    ans.back() = cur.node->val;
                }
            }
            if(cur.node->left != NULL) {
                q.push(T{cur.node->left, cur.dep + 1});
            }
            if(cur.node->right != NULL) {
                q.push(T{cur.node->right, cur.dep + 1});
            }
        }
        return ans;
    }
private:
    struct T {
        TreeNode* node;
        int dep;
    };
};
