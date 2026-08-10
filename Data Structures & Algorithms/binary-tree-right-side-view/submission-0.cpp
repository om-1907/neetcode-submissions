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
void recur(TreeNode* node,int lvl,vector<int>& res){
    if(node==NULL)return ;
    if(res.size()==lvl)res.push_back(node->val);
    recur(node->right,lvl+1,res);
    recur(node->left,lvl+1,res);
}
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        recur(root,0,res);
        return res;
    }
};
