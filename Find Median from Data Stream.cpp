/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

add(1)
add(2)
findMedian() -> 1.5
add(3) 
findMedian() -> 2

*/
class MedianFinder {
private:
    vector<int>v;
public:
    void addNum(int num) {
        //if(v.empty()) v.push_back(num);
        //else{
            auto it=lower_bound(v.begin(),v.end(),num);
            v.insert(it,num);
        //}
    }
    double findMedian() {
        int size=v.size();
        if(size&1) return static_cast<double>(v[size/2]);
        else return static_cast<double>(v[(size-1)/2]+v[size/2])/2;
    }
};
class MedianFinder2 {
private:
	//Max-heap small has the smaller half of the numbers.
	//Min-heap large has the larger half of the numbers.
    priority_queue<long> small, large;
public:
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if (small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
    }

    double findMedian() {
        return small.size() > large.size()
               ? small.top()
               : (small.top() - large.top()) / 2.0;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
