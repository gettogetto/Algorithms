/*
һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�
*/ 
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		int res=0;
        for(int i=0;i<data.size();i++) res^=data[i];
        int k=res^(res-1);//���������ұߵ�1�ڵ�nλ����k=2^n 
        vector<int>tmp1,tmp2;//����k��ԭ����ֳ����ݣ�����������Ҳ�ᱻ�ֿ� 
        for(int i=0;i<data.size();i++){
            if(k&data[i]) tmp1.push_back(data[i]);
            else tmp2.push_back(data[i]);
        }
        int r1=0,r2=0;
        for(int i=0;i<tmp1.size();i++) r1^=tmp1[i];//�ڷֿ��������У��ֱ������һ�ε��� 
        for(int i=0;i<tmp2.size();i++) r2^=tmp2[i];
        
        *num1=r1;
        *num2=r2;
    }
};
