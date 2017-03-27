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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) {
            return sum;
        }
        if(root->left != NULL && isLeaf(root->left)) {
            sum += root->left->val;
        }
        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);
        return sum;
    }
    
    bool isLeaf(TreeNode* node) {
        if(node->left == NULL && node->right == NULL) {
            return true;
        }
        return false;
    }
private:
    int sum = 0;
};
