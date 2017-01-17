struct TreeNode{
	int val;
	TreeNode* left,*right;
	TreeNode(int v):val(v),left(0),right(0){}
	
};
TreeNode* convert(TreeNode* root){
	TreeNode* lastNodeinList=nullptr;
	helper(root,&lastNodeinList);
	TreeNode *head=lastNodeinList;
	while(head&&head->left){
		head=head->left;
	}
	return head;
}

void help(TreeNode* node,TreeNode** plastNode){
	if(root==nullptr) return ;
	TreeNode* cur=node;
	if(cur->left) help(cur->left,plastNode);
	cur->left=*plastNode;
	if(*plastNode){
		(*plastNode)->right=cur;
	}
	*plastNode=cur;
	if(cur->right){
		help(cur->right,plastNode);
	}
}
