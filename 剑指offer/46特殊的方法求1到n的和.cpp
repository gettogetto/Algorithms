//��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
//���ù��캯�� 
class tmp{
public:
    tmp(){
        d++;
        sum+=d;  
    }
	static void set(){
        sum=0;
		d=0;
    }
    static int getsum(){
        return sum;
    }
private:
    static int sum;
    static int d;
};
int tmp::sum=0;
int tmp::d=0;

class Solution {
public:
	
    int Sum_Solution(int n) {
		tmp::set();
        tmp* a=new tmp[n];
        delete []a;
        return tmp::getsum();
    }

};



//���ö�· 
class Solution {
public:
    int Sum_Solution(int n) {
        int sum = n;
        n &&(sum+=Sum_Solution(sum-1));
        return sum;
    }
};

