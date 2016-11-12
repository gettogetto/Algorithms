#include<iostream>
#include<vector>
using namespace std;
//unionfind
class easyuf{
	public:
		easyuf(int n = 0){
			components = n;
			id.resize(n);
			for(int i=0;i<n;i++) id[i]=i;
		}
		void connect(int p,int q){
			int set1=find_set(p);
			int set2=find_set(q);
			if(set1==set2) return ;
			for(int i=0;i<id.size();i++){
				if(id[i]==set1) id[i]=set2;
				
			}
			components--;
		}
		int find_set(int p){
			return id[p];
		}
		bool is_connected(int p,int q){
			return find_set(p)==find_set(q);
		}
		
		int count_components(){
			return components;
		}
		
	private:
		vector<int> id;

		int components;	
		
};
//quickuf without consider the tree size
class quickuf{
	public:
		quickuf(int n = 0){
			components = n;
			id.resize(n);
			for(int i=0;i<n;i++) id[i]=i;
		}
		void connect(int p,int q){
			int root1=find_root(p);
			int root2=find_root(q);
			if(root1==root2) return ;
			
			id[root1]=root2;
			components--;
		}
		int find_root(int p){
			while(id[p]!=p) p=id[p];
			return p;
		}
		bool is_connected(int p,int q){
			return find_root(p)==find_root(q);
		}
		
		int count_components(){
			return components;
		}
		
	private:
		vector<int> id;

		int components;		
};


//quickuf with consider the tree size and path compression 
class superquickuf{
	public:
		superquickuf(int n = 0){
			components = n;
			id.resize(n);
			size.resize(n);
			for(int i=0;i<n;i++) id[i]=i,size[i]=1;
		}
		void connect(int p,int q){
			int root1=find_root(p);
			int root2=find_root(q);
			if(root1==root2) return ;
			//优化1: 
			if(size[root1]<size[root2]){
				id[root1]=root2;//小树连到大树上成为子树 
				size[root1]+=size[root2];
			}
			else{
				id[root2]=root1;
				size[root2]+=size[root1];
			} 
			components--;//合并后，树的数量减一 
		}
		int find_root(int p){
			while(id[p]!=p){
				
				//优化2：p节点的父节点设为它的爷爷节点 
				// 路径压缩，会破坏掉当前节点的父节点的尺寸信息，因为压缩后，当前节点的父节点已经变了  
				id[p]=id[id[p]];
				p=id[p];
			} 
			return p;
		}
		bool is_connected(int p,int q){
			return find_root(p)==find_root(q);
		}
		
		int count_components(){
			return components;
		}
		
	private:
		vector<int> id;//记录每个节点所属的树 
		vector<int> size;//保存树的大小 
		int components;		
};
int main(){
	easyuf uf(5);
	quickuf uf2(5);
	superquickuf uf3(5);
	 
	uf.connect(0,1);
	uf.connect(1,2);
	uf.connect(3,4);
	
	uf2.connect(0,1);
	uf2.connect(1,2);
	uf2.connect(3,4);
	
	uf3.connect(0,1);
	uf3.connect(1,2);
	uf3.connect(3,4);
	cout<<uf.count_components()<<" "<<uf2.count_components()
	<<" "<<uf3.count_components();
}
