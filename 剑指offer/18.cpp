//判断root是不是root1的子树 
bool hasSubtree(TreeNode* root1,TreeNode* root2){
	bool res=false;
	if(root1&&root2){
		if(root1->val==root2->val){
			res=tree1hastree2(root1,root2);
		}
		if(!res) res=hasSubtree(root1->left,root2);
		if(!res) res=hasSubtree(root1->right,root2);
	}
	return res;
}
bool tree1hastree2(TreeNode* root1,TreeNode* root2){
	if(root2==NULL) return true;
	if(root1==NULL) return false;
	if(root1->val!=root2->val){
		return false;
	}
	return tree1hastree2(root1->left,root2->left)&&tree1hastree2(root1->right,root2->right);
}
