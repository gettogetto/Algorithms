/*   3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if(root==NULL) return res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int> onelevel;
            int size=q.size();
            for(int i=0;i<size;++i){
                TreeNode* tmp=q.front();
                onelevel.push_back(tmp->val);
                q.pop();
                if(tmp->left!=NULL) q.push(tmp->left);
                if(tmp->right!=NULL) q.push(tmp->right);
            }
            res.push_back(onelevel);
        }
        return res;
        }
};





