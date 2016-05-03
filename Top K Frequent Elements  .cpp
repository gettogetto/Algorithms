/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:
You may assume k is always valid, 1 ¡Ü k ¡Ü number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/
#include<iostream>
#include<unordered_map>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> map;
    for(int num : nums){
        map[num]++;
    }

    vector<int> res;
    // pair<first, second>: first is frequency,  second is number
    priority_queue<pair<int,int>> pq;
    for(auto it = map.begin(); it != map.end(); it++){
        pq.push(make_pair(it->second, it->first));
        if(pq.size() > (int)map.size() - k){
            res.push_back(pq.top().second);
            pq.pop();
        }
    }
    return res;
}

int main(){

    vector<int>nums={1,1,1,2,2,3,3,3};int k=2;
    vector<int>res=topKFrequent(nums,k);
    for_each(res.begin(),res.end(),[](const int& a){cout<<a<<endl;});
}
