#include<iostream>  
using namespace std;  
  
void merge(int* a, int* temp, int begin, int middle, int end){  
    int i = begin;  
    int j = middle + 1;  
    int k = 0;  
    while (i <= middle&&j <= end){//比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置  
        if (a[i] < a[j])  
            temp[k++] = a[i++];  
        else  
            temp[k++] = a[j++];  
    }  
    while (i <= middle)//若第一个序列有剩余，直接拷贝出来粘到合并序列尾  
        temp[k++] = a[i++];  
    while (j <= end)//若第二个序列有剩余，直接拷贝出来粘到合并序列尾  
        temp[k++] = a[j++];  
    for (i = 0; i < k; i++)//将排序好的序列拷贝回数组中  
        a[begin + i] = temp[i];  
}  
//递归版本  
void merge_sort_recurse(int* a, int* temp, int begin, int end){  
    int middle = (begin + end) >> 1;  
    if (begin < end){  
        merge_sort_recurse(a, temp, begin, middle);//左边有序  
        merge_sort_recurse(a, temp, middle + 1, end);//右边有序  
        merge(a, temp, begin, middle, end);//再将两个有序数列合并  
    }  
}  
//非递归版本，将a中相邻长度为s的子序列两两归并  
void merge_pass(int* a, int* temp, int s, int len){  
    int i = 0;  
    int j;  
    while (i < len - 2 * s + 1){  
        merge(a, temp, i, i + s - 1, i + 2 * s - 1);  
        i += 2 * s;  
    }  
    if (i < len - s + 1)//归并最后两个序列  
        merge(a, temp, i, i + s - 1, len);   
}  
void merge_sort_no_recurse(int* a, int len){  
    int temp[1001];  
    int k = 1;  
    while (k <= len){  
        merge_pass(a, temp, k, len);  
        k *= 2; //子序列长度加倍  
    }  
}  
  
int main(){  
    int num1[1001] = { 50, 10, 90, 30, 70, 40, 80, 60, 20 };  
    int temp1[1001];  
    int num2[1001] = { 50, 10, 90, 30, 70, 40, 80, 60, 20 };  
    int n = 9;  
  
    merge_sort_recurse(num1, temp1, 0, n-1);  
    for (int i = 0; i < n; i++)  
        cout << num1[i] << " ";  
    cout << endl;  
  
    merge_sort_no_recurse(num2, n - 1);  
    for (int i = 0; i < n; i++)  
        cout << num2[i] << " ";  
    cout << endl;  
      
    return 0;  
}  
