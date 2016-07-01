/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        while(true){
            while(root!=nullptr){
                stk.push(root);
                root=root->left;
            }
            root=stk.top();
            stk.pop();
            if(--k!=0) root=root->right;
            else return root->val;
        }
    }
};
