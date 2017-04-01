#include<bits/stdc++.h>
 using namespace std;


 /**�������Ϊ�����֣���pivot��ߵĲ��ֶ�С�����ұߵĲ���**/

 template <typename Comparable>

 int partition(vector<Comparable> &vec,int low,int high){

     Comparable pivot=vec[low];  //��ѡԪ����Ϊ�ᣬ����ѡ��Ԫ��

     while(low<high){

         while(low<high && vec[high]>=pivot)

             high--;

         vec[low]=vec[high];

         while(low<high && vec[low]<=pivot)

             low++;

         vec[high]=vec[low];

     }

     //��ʱlow==high

     vec[low]=pivot;

     return low;

 }



 /**ʹ�õݹ��������**/

 template<typename Comparable>

 void quicksort1(vector<Comparable> &vec,int low,int high){

     if(low<high){

         int mid=partition(vec,low,high);

         quicksort1(vec,low,mid-1);

         quicksort1(vec,mid+1,high);

     }

 }



 /**ʹ��ջ�ķǵݹ��������**/

 template<typename Comparable>

 void quicksort2(vector<Comparable> &vec,int low,int high){

     stack<int> st;

     if(low<high){

         int mid=partition(vec,low,high);//һ�λ���֮�󣬰��ĸ�Ԫ����վ

         if(low<mid-1){

             st.push(low);

             st.push(mid-1);

         }

         if(mid+1<high){

             st.push(mid+1);

             st.push(high);

         }

         //��ʵ������ջ����ÿһ���������Ӵ�����βԪ���±꣬��һ��whileѭ��ʱȡ�������Χ������������н���partition����

         while(!st.empty()){

             int q=st.top();

             st.pop();

             int p=st.top();

             st.pop();

             mid=partition(vec,p,q);

//�����ֵ�����len-1��len-2��Ԫ��ʱ��������жϾͲ�ִ���ˣ�Ȼ���ջ��������Ԫ�ص�����Ȼ��ջ��Ϊ�գ�����������ִ��������жϡ����վԪ��ȫ����������

             if(p<mid-1){

                 st.push(p);

                 st.push(mid-1);

             }

             if(mid+1<q){

                 st.push(mid+1);

                 st.push(q);

             }

         }

     }

 }

 int main(){

     vector<int> v={3,2,4,4,1,12,63,0};
     quicksort2(v,0,v.size()-1);
     for(auto i:v) cout<<i<<" ";


     return 0;

 }
