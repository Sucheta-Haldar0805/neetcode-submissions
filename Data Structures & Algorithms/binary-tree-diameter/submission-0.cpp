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
    pair<int,int> helper(TreeNode* root){ // dia,ht
        if(root == NULL){
            return make_pair(0,-1);
        }
        pair<int,int> leftInfo = helper(root->left);
        pair<int,int> rightInfo = helper(root->right);

        int currDia = leftInfo.second + rightInfo.second + 2;
        int finalDia = max(currDia,max(leftInfo.first,rightInfo.first));
        int finalHt = max(leftInfo.second ,rightInfo.second) + 1;

        return make_pair(finalDia,finalHt);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        return helper(root).first;
    }
};
