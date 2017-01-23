//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
//利用构造函数 
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



//利用短路 
class Solution {
public:
    int Sum_Solution(int n) {
        int sum = n;
        n &&(sum+=Sum_Solution(sum-1));
        return sum;
    }
};

