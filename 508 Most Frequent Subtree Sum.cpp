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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        dfs(root);
        int max_cnt = 0;
        for(auto it = sum_map.begin(); it != sum_map.end(); it++) {
            if(it->second > max_cnt) {
                max_cnt = it->second;
            }
        } 
        for(auto it = sum_map.begin(); it != sum_map.end(); it++) {
            if(it->second == max_cnt) {
                ans.push_back(it->first);
            }
        }
        return ans;
    }
private: 
    void dfs(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        if(root->left != NULL) {
            dfs(root->left);
            root->val += root->left->val;
        }
        if(root->right != NULL) {
            dfs(root->right);
            root->val += root->right->val;
        }
        sum_map[root->val]++;
    }
    
    map<int, int> sum_map;
};
