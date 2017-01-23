/*
����һ�ö����������������ȡ�
�Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·�����·���ĳ���(�ǿս����)Ϊ������ȡ�
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


//��������ƽ��
class Solution {
public:
    /*//��һ 
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
