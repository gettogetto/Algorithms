#include<bits/stdc++.h>
 using namespace std;


 /**把数组分为两部分，轴pivot左边的部分都小于轴右边的部分**/

 template <typename Comparable>

 int partition(vector<Comparable> &vec,int low,int high){

     Comparable pivot=vec[low];  //任选元素作为轴，这里选首元素

     while(low<high){

         while(low<high && vec[high]>=pivot)

             high--;

         vec[low]=vec[high];

         while(low<high && vec[low]<=pivot)

             low++;

         vec[high]=vec[low];

     }

     //此时low==high

     vec[low]=pivot;

     return low;

 }



 /**使用递归快速排序**/

 template<typename Comparable>

 void quicksort1(vector<Comparable> &vec,int low,int high){

     if(low<high){

         int mid=partition(vec,low,high);

         quicksort1(vec,low,mid-1);

         quicksort1(vec,mid+1,high);

     }

 }



 /**使用栈的非递归快速排序**/

 template<typename Comparable>

 void quicksort2(vector<Comparable> &vec,int low,int high){

     stack<int> st;

     if(low<high){

         int mid=partition(vec,low,high);//一次划分之后，把四个元素入站

         if(low<mid-1){

             st.push(low);

             st.push(mid-1);

         }

         if(mid+1<high){

             st.push(mid+1);

             st.push(high);

         }

         //其实就是用栈保存每一个待排序子串的首尾元素下标，下一次while循环时取出这个范围，对这段子序列进行partition操作

         while(!st.empty()){

             int q=st.top();

             st.pop();

             int p=st.top();

             st.pop();

             mid=partition(vec,p,q);

//当划分到最大的len-1和len-2个元素时，下面的判断就不执行了，然后把栈顶这两个元素弹出，然后栈不为空，继续弹出，执行下面的判断。最后站元素全部弹出。。

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
