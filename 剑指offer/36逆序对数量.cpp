
/*
题目描述
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007 
输入描述:
题目保证输入的数组中没有的相同的数字
数据范围：
	对于%50的数据,size<=10^4
	对于%75的数据,size<=10^5
	对于%100的数据,size<=2*10^5
	*/
class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.size()<=1) return 0;
        return mergesort(data,0,data.size()-1)%1000000007 ;
    }
    int mergesort(vector<int> &data,int low,int high){
        if(low>=high) return 0;
        int mid=low+(high-low)/2;
        long long  c1=mergesort(data,low,mid);
        long long c2=mergesort(data,mid+1,high);
        long long c=merge(data,low,high);
        return (c1+c2+c)%1000000007 ;
    }
    int merge(vector<int>&data,int low,int high){
        long long res=0;
        int mid=low+(high-low)/2;
        if(data[mid]<=data[mid+1]) return 0;
        vector<int>tmp(high-low+1);
        int start1=low,end1=mid;
        int start2=mid+1,end2=high;
        int end=high-low;
        while(end1>=start1&&end2>=start2){
            if(data[end1]>data[end2]){
                res+=(end2-start2+1)%1000000007 ;
                tmp[end--]=data[end1--];
                
            }else{
                tmp[end--]=data[end2--];
            }
        }
        while(end1>=start1){
            tmp[end--]=data[end1--];
        }
        while(end2>=start2){
            tmp[end--]=data[end2--];
        }
        for(int i=0;i<high-low+1;i++){
            data[i+low]=tmp[i];
        }
        return res%1000000007 ;
    }
};
