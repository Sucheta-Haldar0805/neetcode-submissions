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
    void levelOrder(TreeNode* root,vector<int>& ans){
        if(root == NULL){
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();

            while(size--){
                auto curr = q.front();
                q.pop();

                if(size == 0){
                    ans.push_back(curr->val);
                }


                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }

        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        levelOrder(root,ans);
        return ans;
    }
};
