#include<iostream>
#include<cmath>
#include<assert.h>
#include<ctime>
namespace YJ{

	float sqrt(float num){
		assert(num>=0);
		float left=0,right=num,mid=left+(right-left)/2,last;
		do{
			
			if(mid*mid>num){
				right=mid;
			}else{
				left=mid;
			}
			last=mid;
			mid=left+(right-left)/2;
		}while(std::abs(mid-last)>0.000001);
		return mid;
	}
	
	float sqrtByNewton(float x)
	{
		assert(x>=0);
		float res = x;
		float lastRes;
		do
		{
			lastRes = res;
			res =(res + x/res) / 2;
		}while(abs(res-lastRes) > 0.000001);
		return res;
	}
}
int main(){
	const float N=2147483647;
	clock_t start1, end1;
	start1 = clock();
	std::cout<<YJ::sqrt(N)<<std::endl;
	end1 = clock();
	std::cout<< double(end1 - start1) << "ms" << std::endl;
	
	start1 = clock();
	std::cout<<YJ::sqrtByNewton(N)<<std::endl;
	end1 = clock();
	std::cout<< double(end1 - start1) << "ms" << std::endl;
	
	start1 = clock();
	std::cout<<std::sqrt(N)<<std::endl;
	end1 = clock();
	std::cout<< double(end1 - start1) << "ms" << std::endl;
}
