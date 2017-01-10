#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
using namespace std;

void perDown(vector<int>&v, int i, int n) {
	int child = 2 * i + 1;
	while (child<n) {
		if (child<n - 1 && v[child]<v[child + 1]) child++;//现在是最大堆，若把<号 改为 >号 将变成最小堆 
		if (v[i]<v[child]) {//现在是最大堆，若把<号 改为 >号 将变成最小堆 
			swap(v[i], v[child]);
			i = child;
			child = 2 * i + 1;	//每次向下跳一层，一共logN层 
		}
		else break;
	}
}
//NlogN 
void heapSort(vector<int>&v) {
	int N = v.size();
	for (int i = N / 2; i >= 0; i--) {
		perDown(v, i, N);//建立最大堆 ，用于升序排列 
	}
	for (int i = N - 1; i>0; i--) {
		swap(v[0], v[i]);//每次将堆首和最后一个原素交换，用于升序 
		perDown(v, 0, i);
	}
}


void quickSort(vector<int>& v, int left, int right) {
	if (left >= right) return;
	int low = left;
	int high = right;
	int key = v[left];
	while (low<high) {
		while (low<high&&v[high] >= key) high--;
		v[low] = v[high];
		while (low<high&&v[low] <= key) low++;
		v[high] = v[low];
	}
	v[low] = key;
	quickSort(v, left, low - 1);
	quickSort(v, low + 1, right);
}
void threeWayQuickSort(vector<int>&v, int left, int right) {
	if (left >= right) return;
	int key = v[left];
	int lt = left, gt = right, i = lt + 1;
	while (i <= gt) {
		if (v[i]<key) swap(v[i++], v[lt++]);
		else if (v[i]>key) swap(v[i], v[gt--]);
		else i++;
	}
	threeWayQuickSort(v, left, lt - 1);
	threeWayQuickSort(v, gt + 1, right);
}

void selectSort(vector<int>& v) {
	int N = v.size();
	for (int i = 0; i<N; i++) {
		int minIndex = i;
		for (int j = i + 1; j<N; j++) {
			if (v[j]<v[minIndex]) minIndex = j;
		}
		if (minIndex != i) {
			swap(v[i], v[minIndex]);
		}
	}
}


void bubbleSort(vector<int>&v) {
	int N = v.size();
	for (int i = 0; i<N - 1; i++) {
		for (int j = N; j>i; j--) {
			if (v[j]<v[j - 1]) swap(v[j], v[j - 1]);
		}
	}
}

void insertSort(vector<int>&v) {
	int N = v.size();
	for (int i = 1; i<N; i++) {
		int tmp = v[i];
		int j;
		for (j = i - 1; j >= 0 && v[j]>tmp; j--) {
			v[j + 1] = v[j];
		}
		v[j + 1] = tmp;
	}
}
void shellSort(vector<int>&v) {
	int N = v.size();
	int d = N / 2;
	while (d>0) {//d=1相当于插入排序 
		for (int i = d; i<N; i += d) {
			int tmp = v[i];
			int j;
			for (j = i - d; j >= 0 && v[j]>tmp; j -= d) {
				v[j + d] = v[j];
			}
			v[j + d] = tmp;
		}
		d >>= 1;
	}
}


void merge(vector<int>&v, int low, int high) {

	int mid = low + (high - low) / 2;

	if (v[mid] <= v[mid + 1]) return;

	int low1 = low;
	int low2 = mid + 1;

	vector<int>tmp;

	while (low1 <= mid&&low2 <= high) {
		v[low1]<v[low2] ? tmp.push_back(v[low1++]) : tmp.push_back(v[low2++]);
	}
	while (low1 <= mid) {
		tmp.push_back(v[low1++]);
	}
	while (low2 <= high) {
		tmp.push_back(v[low2++]);
	}

	for (int i = low; i <= high; i++) {
		v[i] = tmp[i - low];
	}
}
void mergeSort(vector<int>&v, int low, int high) {
	if (low >= high) return;
	int mid = low + (high - low) / 2;
	mergeSort(v, low, mid);
	mergeSort(v, mid + 1, high);
	merge(v, low, high);
}


int maxbit(vector<int>&data) //辅助函数，求数据的最大位数
{
	int n = data.size();
	int d = 1; //保存最大的位数
	int p = 10;
	for (int i = 0; i < n; ++i)
	{
		while (data[i] >= p)
		{
			p *= 10;
			++d;
		}
	}
	return d;
}
void radixSort(vector<int>&data) //基数排序
{
	int n = data.size();
	int d = maxbit(data);
	vector<int>tmp(n, 0);
	vector<int>count(10, 0);

	int i, j, k;
	int radix = 1;
	for (i = 1; i <= d; i++) //进行d次排序
	{
		for (j = 0; j < 10; j++)
			count[j] = 0; //每次分配前清空计数器
		for (j = 0; j < n; j++)
		{
			k = (data[j] / radix) % 10; //统计每个桶中的记录数
			count[k]++;
		}
		for (j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
		for (j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
		{
			k = (data[j] / radix) % 10;
			tmp[count[k] - 1] = data[j];
			count[k]--;
		}
		for (j = 0; j < n; j++) //将临时数组的内容复制到data中
			data[j] = tmp[j];
		radix = radix * 10;
	}
}

//计数排序 O(n+k);需要O(n+k)额外空间
void countingSort(vector<int>& nums){
	int maxValueInNums=0;
	for(auto num:nums){
		maxValueInNums=max(maxValueInNums,num);
	}
	vector<int>count(maxValueInNums+1,0);
	for(auto num:nums){
		count[num]++;
	}
	for(int i=1;i<count.size();i++){
		count[i]=count[i]+count[i-1];
	}
	vector<int>tmpVector(nums.size(),0);
	for(int i=tmpVector.size()-1;i>=0;i--){
		tmpVector[count[nums[i]]]=nums[i];
		nums[i]--;
	}
	for(int i=0;i<nums.size();i++){
		nums[i]=tmpVector[i];
	}
} 

int main() {
	vector<int> v(10000, 0);

	clock_t start1, end1;
	for (int i = 0; i<5; i++) {

		for (int i = 0; i<v.size(); i++) v[i] = rand(); start1 = clock(); radixSort(v); end1 = clock(); cout << "radix sort  " << double(end1 - start1) << "ms" << endl;
		
		for (int i = 0; i<v.size(); i++) v[i] = rand(); start1 = clock(); countingSort(v); end1 = clock(); cout << "counting sort  " << double(end1 - start1) << "ms" << endl;

		for (int i = 0; i<v.size(); i++) v[i] = rand(); start1 = clock(); sort(v.begin(), v.end()); end1 = clock(); cout << "stl sort  " << double(end1 - start1) << "ms" << endl;

		for (int i = 0; i<v.size(); i++) v[i] = 1; start1 = clock(); threeWayQuickSort(v, 0, v.size() - 1); end1 = clock(); cout << "threeWayQuickSort  " << double(end1 - start1) << "ms" << endl;

		for (int i = 0; i<v.size(); i++) v[i] = 1; start1 = clock(); quickSort(v, 0, v.size() - 1); end1 = clock(); cout << "quickSort  " << double(end1 - start1) << "ms" << endl;

		for (int i = 0; i<v.size(); i++) v[i] = rand(); start1 = clock(); heapSort(v); end1 = clock(); cout << "heapSort  " << double(end1 - start1) << "ms" << endl;


		for (int i = 0; i<v.size(); i++) v[i] = rand(); start1 = clock(); mergeSort(v, 0, v.size() - 1); end1 = clock(); cout << "mergeSort  " << double(end1 - start1) << "ms" << endl;

		for (int i = 0; i<v.size(); i++) v[i] = rand(); start1 = clock(); shellSort(v); end1 = clock(); cout << "shellSort  " << double(end1 - start1) << "ms" << endl;

		for (int i = 0; i<v.size(); i++) v[i] = rand(); start1 = clock(); insertSort(v); end1 = clock(); cout << "insertSort  " << double(end1 - start1) << "ms" << endl;

		for (int i = 0; i<v.size(); i++) v[i] = rand(); start1 = clock(); selectSort(v); end1 = clock(); cout << "selectSort  " << double(end1 - start1) << "ms" << endl;

		for (int i = 0; i<v.size(); i++) v[i] = rand(); start1 = clock(); bubbleSort(v); end1 = clock(); cout << "bubbleSort  " << double(end1 - start1) << "ms" << endl;

		cout << "========================================" << endl;
		
	}
	//for(auto i:v) cout<<i<<" ";
	getchar();
	
}

