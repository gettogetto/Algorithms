/*
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
*/
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
    int maxValue;
    int maxPathSum(TreeNode* root) {
        if(root==nullptr) return 0;
        maxValue=INT_MIN;
        maxPathDown(root);
        return maxValue;
    }
    int maxPathDown(TreeNode* root){
        if(root==nullptr) return 0;
        int left=max(maxPathDow n(root->left),0);
        int right=max(maxPathDown(root->right),0);
        maxValue=max(maxValue,left+right+root->val);
        return max(left,right)+root->val;
    }
};
