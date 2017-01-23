//二分查找找第一个和最后一个k，然后作差，可得k出现次数 
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int l=getfirstk(data,k,0,data.size()-1);
        int r=getlastk(data,k,0,data.size()-1);
        if(l>=0&&r>=0) return r-l+1;
        else return 0;
    }
    int getfirstk(vector<int> data,int k,int left,int right){
		if(left>right) return -1;
        int mid=left+(right-left)/2;
        if(data[mid]>k){
            return getfirstk(data,k,left,mid-1);
        }else if(data[mid]<k){
            return getfirstk(data,k,mid+1,right);
        }else{
            if(mid>0&&data[mid-1]!=k) return mid;
            if(mid>0&&data[mid-1]==k) return getfirstk(data,k,left,mid-1);
            if(mid==0) return mid;
        }
        return -1;
    }
    int getlastk(vector<int>data,int k,int left,int right){
        if(left>right) return -1;
        int mid=left+(right-left)/2;
        if(data[mid]>k){
            return getlastk(data,k,left,mid-1);
        }else if(data[mid]<k){
            return getlastk(data,k,mid+1,right);
        }else{
            if(mid<data.size()-1&&data[mid+1]!=k) return mid;
            if(mid<data.size()-1&&data[mid+1]==k) return getlastk(data,k,mid+1,right);
            if(mid==data.size()-1) return mid;
        }
        return -1;
    }
};
