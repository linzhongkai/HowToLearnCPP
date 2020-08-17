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
    bool isBalanced(TreeNode* root) {
        return height(root) >= 0;             
    }
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        int lheight = height(root->left); //自底向上的递归
        int rheight = height(root->right);
        if(lheight == -1 || rheight == -1 || abs(lheight - rheight) > 1){
            return -1;
        }
        else{
            return max(lheight, rheight) + 1;
        }
    }
};
