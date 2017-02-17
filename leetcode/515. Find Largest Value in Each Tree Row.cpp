/*
You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root==nullptr) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size= q.size();
            int rowmax=INT_MIN;
            for(int i=0;i<size;i++){
                auto tmp = q.front();
                rowmax=max(rowmax,tmp->val);
                q.pop();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            res.push_back(rowmax);
        }
        return res;
    }
};
