/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* pre=nullptr;//上次访问的节点
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* cur=s.top();
            if((cur->left==nullptr&&cur->right==nullptr)||(pre!=nullptr&&(pre==cur->left||pre==cur->right))){
                s.pop();
                res.push_back(cur->val);
                pre=cur;
            }else{
                if(cur->right){
                    s.push(cur->right);
                }
                if(cur->left){
                    s.push(cur->left);
                }
            }
        }
        return res;
    }
};
