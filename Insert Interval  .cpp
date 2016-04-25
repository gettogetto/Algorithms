/**
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]. 
*/
/*

 * Definition for an interval.

 * struct Interval {

 *     int start;

 *     int end;

 *     Interval() : start(0), end(0) {}

 *     Interval(int s, int e) : start(s), end(e) {}

 * };

 */
class Solution {
	public:
		vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
			int n=intervals.size();
			if(intervals.empty()) {
				intervals.push_back(newInterval);
				return intervals;
			}
			for(int i=0; i<n; i++) {
				if(newInterval.start<intervals[i].start) {
					intervals.insert(intervals.begin()+i,newInterval);
					break;
				}
			}
			if(newInterval.start>=intervals[n-1].start) {
				intervals.insert(intervals.end(),newInterval);
			}
			return merge(intervals);
		}
		vector<Interval> merge(vector<Interval>& intervals) {
			int n=intervals.size();
			vector<Interval>res;
			if(n==0) return res;
			res=intervals;
			/*

			sort(res.begin(),res.end(),

			    [](const Interval& interval1,const Interval& interval2){

			        return (interval1.start<interval2.start);

			    }

			);*/
			stack<Interval>s;
			s.push(res[0]);
			for(int i=1; i<n; i++) {
				Interval pre=s.top();
				Interval cur=res[i];
				if(pre.end<cur.start) {
					s.push(cur);
				} else {
					s.pop();
					//pre.start=min(pre.start,cur.start);
					pre.end=max(pre.end,cur.end);
					s.push(pre);
				}
			}
			//res.clear();
			res.resize(s.size());
			int k=s.size()-1;
			while(!s.empty()) {
				res[k--]=s.top();
				s.pop();
			}
			return res;
		}
};
class Solution2 {
	public:
		vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
			vector<Interval> res;
			int index = 0;
			while(index < intervals.size() && intervals[index].end < newInterval.start) {
				res.push_back(intervals[index++]);
			}
			while(index < intervals.size() && intervals[index].start <= newInterval.end) {
				newInterval.start = min(newInterval.start, intervals[index].start);
				newInterval.end = max(newInterval.end, intervals[index].end);
				index++;
			}
			res.push_back(newInterval);
			while(index < intervals.size()) {
				res.push_back(intervals[index++]);
			}
			return res;
		}
};
