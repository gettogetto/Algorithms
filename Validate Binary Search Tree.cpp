/**
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/
 /*
class Solution {
    vector<int>v;
public:
    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return 1;
        inorderTravel(root);
        return is_sorted(v.begin(),v.end(),less_equal<int>());
    }
    void inorderTravel(TreeNode* root){
        if(root==nullptr) return;
        inorderTravel(root->left);
        v.push_back(root->val);
        inorderTravel(root->right);
    }

};*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
};
