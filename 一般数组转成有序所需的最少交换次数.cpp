#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
int GetMinimumSwapsForSorted(T seq[], int n)
{
    bool* right_place_flag = new bool[n];
    T* sorted_seq = new T[n];
    int p ,q;
    ////
    copy(seq, seq + n, sorted_seq);
    sort(sorted_seq, sorted_seq + n);    ////可采用效率更高的排序算法
    ////
    for(int i = 0; i < n; i++)
    {
        if(seq[i] != sorted_seq[i])
            right_place_flag[i] = false;
        else
            right_place_flag[i] = true;
    }
    ////
    p = 0;
    int minimumswap = 0;
    while(1)
    {
        while(right_place_flag[p])
            p++;
        q = p + 1;
        ////此种找法只对无重复序列能得出minimum swaps
        while(q < n)
        {
            if(!right_place_flag[q] && sorted_seq[q] == seq[p])
                break;
            q++;
        }
        if(q >= n || p >= n)
            break;
        right_place_flag[q] = true;
        if(seq[q] == sorted_seq[p])
            right_place_flag[p] = true;
        swap(seq[p], seq[q]);
        minimumswap++;
    }
    delete[] sorted_seq;
    delete[] right_place_flag;
    return minimumswap;
}

int main()
{
    int seq[] = {3, 2, 1, 5, 6, 8, 4, 7 };//{2,3,1,5,6,4};//{2,3,2,4,7,6,3,5};
    int n = sizeof(seq) / sizeof(int);
    cout<<"minimum swaps : "<<GetMinimumSwapsForSorted(seq, n)<<endl;
    system("pause");
    return 0;
}
