/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3 

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]
*/
//法一 ，利用优先队列 
class Solution {
public:
    struct com{
        bool operator()(pair<int,int>& a,pair<int,int>& b){
            return a.first+a.second<b.first+b.second;
        }
    };
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue< pair<int,int>,vector<pair<int,int> >,com > pq;//最大堆用<号，最小堆用>号 
        for(int i=0;i<min((int)nums1.size(),k);i++){
            for(int j=0;j<min((int)nums2.size(),k);j++){
                if(pq.size()<k){
                    pq.push(make_pair(nums1[i],nums2[j]));
                }else if(nums1[i]+nums2[j]<pq.top().first+pq.top().second){
                        
                    pq.push(make_pair(nums1[i],nums2[j]));
                        
                    pq.pop();
                    
                }
            }
        }
        vector<pair<int,int> >res(pq.size());
        int i=0;
        while(!pq.empty()){
            res[i++]=pq.top();
            pq.pop();
        }
        return res;
    }
};
//法二
class Solution2 {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m=nums1.size();
        int n=nums2.size();
        k=min(k,m*n);
        vector<pair<int,int> > res;
        vector<int> indice(m,0);//表示数组1中元素下标i,对应的数组2的元素下标indice[i] 
        while(k--){
            int tmp_index=0;
            int tmp_min_sum=LONG_MAX;
            //寻找最小sum的下标组合 
            for(int i=0;i<m;i++){
                if(indice[i]<n&&tmp_min_sum>=nums1[i]+nums2[indice[i]]){
                    tmp_index=i;
                    tmp_min_sum=nums1[i]+nums2[indice[i]];
                }
            }
            
            res.push_back({nums1[tmp_index],nums2[indice[tmp_index]]});
            indice[tmp_index]++;// 找到一个结果，数组1下标i,对应的数组2的下标indice[i]往右走一位 
        }
        return res;
    }
}; 
