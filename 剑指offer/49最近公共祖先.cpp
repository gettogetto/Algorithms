//BST
//递归 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p -> val < root -> val && q -> val < root -> val)
            return lowestCommonAncestor(root -> left, p, q);
        if (p -> val > root -> val && q -> val > root -> val)
            return lowestCommonAncestor(root -> right, p, q);
        return root;
    }

};
//迭代 
class Solution { 
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        while (true) {
            if (p -> val < cur -> val && q -> val < cur -> val)
                cur = cur -> left;
            else if (p -> val > cur -> val && q -> val > cur -> val)
                cur = cur -> right;
            else return cur; 
        }
    }
};
/*************************************************/
//普通二叉树 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(root==p||root==q) return root;
        
        
        TreeNode* l=lowestCommonAncestor(root->left,p,q);
        TreeNode* r=lowestCommonAncestor(root->right,p,q);
        if(l&&r) return root;
        if(!l) return r;
        if(!r) return l;
        return root;
        
    }
};
//路径法 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> cur,p_path,q_path;
        
        dfs(root,p,q,cur,p_path,q_path);
        TreeNode *res=root;
        for(int i=0;i<min(p_path.size(),q_path.size());i++){
            if(p_path[i]==q_path[i]){
                res=p_path[i];
            }else{
                break;
            }
            
        }
        return res;
        
    }
    void dfs(TreeNode* root,TreeNode* p,TreeNode* q,vector<TreeNode*> &cur,vector<TreeNode*> &p_path,vector<TreeNode*> &q_path){
        if(root==nullptr) return;
        cur.push_back(root);
        if(root==p){
            p_path=cur;
        }
        if(root==q){
            q_path=cur;
        }
        dfs(root->left,p,q,cur,p_path,q_path);
        
        dfs(root->right,p,q,cur,p_path,q_path);
        cur.pop_back();//若形参cur不是引用，则删掉此句 
    }
};
