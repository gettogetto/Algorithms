#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define N 10         // 带编码字符的个数，即树中叶结点的最大个数  
#define M (2*N-1)    // 树中总的结点数目  

class HTNode {       // 树中结点的结构
	public:
		unsigned int weight;
		unsigned int parent,lchild,rchild;
};

class HTCode {
	public:
		char data;      // 待编码的字符
		int weight;     // 字符的权值
		char code[N];   // 字符的编码
};

void Init(HTCode hc[], int *n) {
// 初始化，读入待编码字符的个数n，从键盘输入n个字符和n个权值
	int i;
	printf("input n = ");

	cin>>*n;

	printf("\ninput %d character\n",*n);

	for(i=1; i<=*n; ++i)
		cin>>hc[i].data;


	printf("\ninput %d weight\n",*n);

	for(i=1; i<=*n; ++i)
		cin>>hc[i].weight;

}//

void Select(HTNode ht[], int k, int *s1, int *s2) {
// ht[1...k]中选择parent为0，并且weight最小的两个结点，其序号由指针变量s1，s2指示
	int i;
	for(i=1; i<=k && ht[i].parent != 0; ++i) ;
	
	*s1 = i;

	for(i=1; i<=k; ++i) {
		if(ht[i].parent==0 && ht[i].weight<=ht[*s1].weight)
			*s1 = i;
	}

	for(i=1; i<=k; ++i) {
		if(ht[i].parent==0 && i!=*s1) {
			*s2 = i;
			break;
		}

	}

	for(i=1; i<=k; ++i) {
		if(ht[i].parent==0 && i!=*s1 && ht[i].weight<=ht[*s2].weight)
			*s2 = i;
	}
}

void HuffmanCoding(HTNode ht[],HTCode hc[],int n) {
// 构造Huffman树ht，并求出n个字符的编码
	char cd[N];
	int i,j,m,c,f,s1,s2,start;
	m = 2*n-1;

	for(i=1; i<=m; ++i) {
		if(i <= n)
			ht[i].weight = hc[i].weight;
		else
			ht[i].weight = 0;
		ht[i].parent = ht[i].lchild = ht[i].rchild = 0;
	}

	for(i=n+1; i<=m; ++i) {
		Select(ht, i-1, &s1, &s2);
		ht[s1].parent = i;
		ht[s2].parent = i;
		ht[i].lchild = s1;
		ht[i].rchild = s2;
		ht[i].weight = ht[s1].weight+ht[s2].weight;
	}

	cd[n-1] = '\0';

	for(i=1; i<=n; ++i) {
		start = n-1;
		for(c=i,f=ht[i].parent; f; c=f,f=ht[f].parent) {
			if(ht[f].lchild == c)
				cd[--start] = '0';
			else
				cd[--start] = '1';
		}
		strcpy(hc[i].code, &cd[start]);
	}
}


int main() {
	int i,m,n,w[N+1];
	HTNode ht[M+1];
	HTCode hc[N+1];
	Init(hc, &n);     // 初始化
	HuffmanCoding(ht,hc,n);   // 构造Huffman树，并形成字符的编码

	for(i=1; i<=n; ++i)
		printf("\n%c---%s",hc[i].data,hc[i].code);
	return 0;
}
