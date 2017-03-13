//快排的递归  
void quickSort1(int* root,int low,int high)  
{  
    int pat=root[low];  
    if(low<high)  
    {  
        int i=low,j=high;  
        while(i<j)  
        {     
            while(i<j&&root[j]>pat)  
                j--;  
            root[i]=root[j];  
  
  
            while(i<j&&root[i]<pat)  
                i++;  
            root[j]=root[i];  
  
        }  
        root[i]=pat;  
        quickSort1(root,low,i-1);  
        quickSort1(root,i+1,high);  
    }  
      
}  
  
//快排的非递归  
int partion(int* root,int low,int high)  
{  
    int part=root[low];  
    while(low<high)  
    {  
        while(low<high&&root[high]>part) high--;  
        root[low]=root[high];  
        while(low<high&&root[low]<part) low++;  
        root[high]=root[low];  
    }  
    root[low]=part;  
    return low;  
}  
  
void quickSort2(int* root,int low,int high)  
{  
    stack<int> st;  
    int k;  
    if(low<high)  
    {  
        st.push(low);  
        st.push(high);  
        while(!st.empty())  
        {  
            int j=st.top();st.pop();  
            int i=st.top();st.pop();  
  
            k=partion(root,i,j);  
  
            if(i<k-1)  
            {  
                st.push(i);  
                st.push(k-1);  
            }  
            if(k+1<j)  
            {  
                st.push(k+1);  
                st.push(j);  
            }  
        }  
  
    }  
      
}  
