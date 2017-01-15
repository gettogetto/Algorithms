/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==nullptr){
            return false;
        }
        if(sum==root->val&&!root->left&&!root->right) return true;
        return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
    }
};
/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int>path;
        treePaths(root,sum,path,res);
        return res;
    }
    void treePaths(TreeNode* root,int sum,vector<int>path,vector<vector<int>>&res){
        if(root==nullptr) return;
        path.push_back(root->val);
        if(root->left==nullptr&&root->right==nullptr&&sum==root->val){
                res.push_back(path);
        }
        treePaths(root->left,sum-root->val,path,res);
        treePaths(root->right,sum-root->val,path,res);
    }
};
//上面path形参不是引用，改为引用后需要最后加两句回溯 
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int>path;
        treePaths(root,sum,path,res);
        return res;
    }
    void treePaths(TreeNode* root,int sum,vector<int>&path,vector<vector<int>>&res){
        if(root==nullptr) return;
        path.push_back(root->val);
        if(root->left==nullptr&&root->right==nullptr&&sum==root->val){
                res.push_back(path);
        }
        treePaths(root->left,sum-root->val,path,res);
        treePaths(root->right,sum-root->val,path,res);
        path.pop_back();//回溯 
        sum+=root->val;//回溯 
    }
};

/*
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
*/

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL) return 0;
        return sumUp(root,0,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
    }
    int sumUp(TreeNode* root,int pre,int &sum){
        if(!root) return 0;
        int current = pre + root->val;
        return (current == sum) + sumUp(root->left, current, sum) + sumUp(root->right, current, sum);
    }
};
