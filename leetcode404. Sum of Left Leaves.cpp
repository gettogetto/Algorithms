/*
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
*/ 
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL) return 0;

        if(root->left&&!root->left->left&&!root->left->right) return root->left->val+sumOfLeftLeaves(root->right);
        return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);

    }
};

//µü´ú·¨ 
class Solution {
    public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = 0;
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty()) {
            TreeNode* node = s.top();s.pop();
            if(node->left != nullptr) {
                if (node->left->left == nullptr && node->left->right == nullptr)
                    ans += node->left->val;
                else
                    s.push(node->left);
            }
            if(node->right != nullptr) {
                if (node->right->left != nullptr || node->right->right != nullptr)
                    s.push(node->right);
            }
        }
        return ans;
    }
};
