#include<iostream>
#include<vector>
using namespace std;
class NumArray {
private:
    class segmentTreeNode{
        public:
            int start,end,sum;
            segmentTreeNode* left,*right;
        public:
            segmentTreeNode(int i,int j):start(i),end(j),sum(0),left(0),right(0){}
    };
    segmentTreeNode* root;
    segmentTreeNode* build(vector<int>&nums,int i,int j){
        if(i>j) return nullptr;
        int mid=i+(j-i)/2;
        segmentTreeNode* root=new segmentTreeNode(i,j);
        if(i==j){
            root->sum=nums[i];
            return root;
        }
        root->left=build(nums,i,mid);
        root->right=build(nums,mid+1,j);
        root->sum=root->left->sum+root->right->sum;
        return root;
    }
    void setValue(segmentTreeNode* root,int i,int val){
        if(root==nullptr) return;
        
        if(root->left==nullptr&&root->right==nullptr){//if(root->start==root->end)
            root->sum=val;
            return;
        }
        int mid=(root->start+(root->end-root->start)/2);
        if(i<=mid) setValue(root->left,i,val);
        else setValue(root->right,i,val);
        
        root->sum=root->left->sum+root->right->sum;
        return;
    }
    int query(segmentTreeNode* root,int i,int j){
        if(i>j) return 0;
        if(root->start==i&&root->end==j) return root->sum;
        int mid=root->start+(root->end-root->start)/2;
        return query(root->left,i,min(j,mid))+query(root->right,max(mid+1,i),j);
    }
public:
    NumArray(vector<int> &nums) {
        int n=nums.size();
        root=build(nums,0,n-1);
    }

    void update(int i, int val) {
        setValue(root,i,val);
        return;
    }

    int sumRange(int i, int j) {
        return query(root,i,j);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);

class NumArray2 {
private:
    std::vector<int> bitTree;
    std::vector<int>& inputArr;
    int mLen;
    void updateDiff(int i, int diff){
        i++;
        while(i <= mLen){
            bitTree[i] += diff;
            i = getNext(i);
        }    
    }

    int getPrevious(int index){
        return index & (index-1);
    }

    int getNext(int index){
        return 2*index-(index & (index-1));
    }

    void createBIT(){
        for(int i=0; i< mLen; i++){
            updateDiff(i, inputArr[i]);
        }
    }


public:
    NumArray2(vector<int> &nums):inputArr(nums), mLen(nums.size()) 
                                ,bitTree(nums.size()+1, 0) 
    {
        createBIT();
    }

    void update(int i, int val) {
        updateDiff(i, val-inputArr[i]);
        inputArr[i] = val;
    }

    int sumRange(int i, int j) {
        if(i > 0){
            return sumRange(0, j)- sumRange(0, i-1);
        }
        j++;
        int sum = 0;
        while (j > 0) {
            sum += bitTree[j];
            j = getPrevious(j);
        }
        return sum;
    }
};
int main(){
	vector<int>nums={0,9,5,7,3};
	NumArray numarray(nums);
	cout<<numarray.sumRange(0,2)<<endl;
	numarray.update(1,2);
	cout<<numarray.sumRange(0,2)<<endl;
	
}
