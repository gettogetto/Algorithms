/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int n=intervals.size();
        vector<Interval>res;
        if(n==0) return res;
        res=intervals;
        sort(res.begin(),res.end(),
            [](const Interval& interval1,const Interval& interval2){
                return (interval1.start<interval2.start);
            }
        );
        stack<Interval>s;
        s.push(res[0]);
        for(int i=1;i<n;i++){
            Interval pre=s.top();
            Interval cur=res[i];
            if(pre.end<cur.start){
                s.push(cur);
            }else{
                s.pop();
                //pre.start=min(pre.start,cur.start);
                pre.end=max(pre.end,cur.end);
                s.push(pre);
            }
        }
        //res.clear();
        res.resize(s.size());
        int k=s.size()-1;
        while(!s.empty()){
            res[k--]=s.top();
            s.pop();
        }
        return res;
    }
};
