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
    int goodnodes=0; 
    void getgoodnode(TreeNode* node,int grtnum) {
        if(!node)return ;
        if(node->val>=grtnum)goodnodes++;
        grtnum=max(node->val,grtnum);
        getgoodnode(node->left,grtnum);
        getgoodnode(node->right,grtnum);
    }
    int goodNodes(TreeNode* root) {
        getgoodnode(root,root->val);
        return goodnodes;
    }
};
