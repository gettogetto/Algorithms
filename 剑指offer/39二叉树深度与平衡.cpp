/*
输入一棵二叉树，求该树的深度。
从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度(非空结点数)为树的深度。
*/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
    	if(pRoot==nullptr) return 0;
        return 1+max(TreeDepth(pRoot->left),TreeDepth(pRoot->right));
       
    }
};


//二叉树的平衡
class Solution {
public:
    /*//法一 
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot==nullptr) return true;
		int lefth=TreeDepth(pRoot->left);
        int righth=TreeDepth(pRoot->right);
        return abs(lefth-righth)<=1&&IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right);
    }
    int TreeDepth(TreeNode* pRoot)
    {
    	if(pRoot==nullptr) return 0;
        return 1+max(TreeDepth(pRoot->left),TreeDepth(pRoot->right));
       
    }
    */
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot==nullptr) return true;
        return dfs(pRoot)!=-1;
    }
    int dfs(TreeNode* pRoot){
        if(pRoot==nullptr) return 0;
		int lefth=dfs(pRoot->left);
        if(lefth==-1) return -1;
        int righth=dfs(pRoot->right);
        if(righth==-1) return -1;
        
        if(abs(lefth-righth)>1) return -1;
        else return 1+max(lefth,righth);
    }
}; 
