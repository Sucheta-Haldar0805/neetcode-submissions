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
    int helper(TreeNode* root,int maxi){
         if(root == NULL) {
            return 0;
        }
        int cnt = 0;
        if(root->val >= maxi){
            cnt = 1;
        }
        maxi = max(root->val,maxi);
        return cnt + helper(root->left,maxi) + helper(root->right,maxi);
    }
    int goodNodes(TreeNode* root) {
       
        return helper(root,root->val);
    }
};
