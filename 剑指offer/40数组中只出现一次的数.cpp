/*
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
*/ 
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		int res=0;
        for(int i=0;i<data.size();i++) res^=data[i];
        int k=res^(res-1);//二进制最右边的1在第n位，即k=2^n 
        vector<int>tmp1,tmp2;//根据k将原数组分成两份，两个所求结果也会被分开 
        for(int i=0;i<data.size();i++){
            if(k&data[i]) tmp1.push_back(data[i]);
            else tmp2.push_back(data[i]);
        }
        int r1=0,r2=0;
        for(int i=0;i<tmp1.size();i++) r1^=tmp1[i];//在分开的数组中，分别求出现一次的数 
        for(int i=0;i<tmp2.size();i++) r2^=tmp2[i];
        
        *num1=r1;
        *num2=r2;
    }
};
