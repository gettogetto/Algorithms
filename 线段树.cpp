
#include<bits/stdc++.h>
using namespace std;
class SegmentTreeNode {
public:
  int start, end, max;
  SegmentTreeNode *left, *right;
  SegmentTreeNode(int start=0, int end=0, int max=INT_MIN) {
      this->start = start;
      this->end = end;
      this->max = max;
      this->left = this->right = NULL;
  }
};



SegmentTreeNode * build(vector<int>& A,int l,int r){
    if(l>r)
        return NULL;  
    SegmentTreeNode *root=new SegmentTreeNode(l,r);
    if(l<r){

        int mid=l+(r-l)/2;
        root->left=build(A,l,mid);
        root->right=build(A,mid+1,r);
        root->max=max(root->left->max,root->right->max);
    }else{
        root->max=A[l];    
    }
    return root;
}
    


//////////////////////////////////////////////////////////////////////



int query(SegmentTreeNode *root, int start, int end) {
    if (start > end) {
        return INT_MIN;
    }
    if (start == root->start && end == root->end) {
        return root->max;
    }
    int mid = root->start + (root->end - root->start )/2;
    int ans = INT_MIN;
    ans = max(ans, query(root->left, start, min(end, mid)));
    ans = max(ans, query(root->right, max(start, mid + 1), end));
    return ans;
}
///////////////////////////////////////////////////////////////////////

    /**
     *@param root, index, value: The root of segment tree and 
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
void modify(SegmentTreeNode *root, int index, int value) {
    if (root->start == root->end) {
        root->max = value;
        return;
    }
    int mid = root->start + (root->end - root->start) / 2;
    if (index <= mid) {
        modify(root->left, index, value);
    } else {
        modify(root->right, index, value);
    }
    root->max = max(root->left->max, root->right->max);
}

int main(){
	vector<int> v={5,4,30,2,1};
	SegmentTreeNode* root=build(v,0,v.size()-1);
	cout<<query(root,2,3)<<endl;
	modify(root,2,50);
	cout<<query(root,2,3)<<endl;
}

