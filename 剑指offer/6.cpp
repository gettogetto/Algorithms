/*Construct Binary Tree from Preorder and Inorder Traversal*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    TreeNode* helper(vector<int>& preorder,int left1,int right1, vector<int>& inorder,int left2,int right2){
        if(left1>right1) return nullptr;
        int rootValue=preorder[left1];
        int i;
        for(i=left2;i<=right2;i++){
            if(inorder[i]==rootValue) break;
        }
        TreeNode* root=new TreeNode(rootValue);
        root->left=helper(preorder,left1+1,left1+i-left2,inorder,left2,i-1);
        root->right=helper(preorder,right1-(right2-i-1),right1,inorder,i+1,right2);
        return root;
    }
};

/*Given inorder and postorder traversal of a tree, construct the binary tree.*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
    TreeNode* helper(vector<int>& inorder,int left1,int right1, vector<int>& postorder,int left2,int right2){
        if(left2>right2) return NULL;
        int rootValue=postorder[right2];
        int i;
        for(i=left1;i<right1;i++){
            if(inorder[i]==rootValue) break;
        }
        TreeNode* root=new TreeNode(rootValue);
        root->left=helper(inorder,left1,i-1,postorder,left2,left2+(i-1-left1));
        root->right=helper(inorder,i+1,right1,postorder,right2-1-(right1-i-1),right2-1);
        return root;
    }
};
