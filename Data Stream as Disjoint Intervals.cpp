/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 //法1 
class SummaryRanges {
private:
    vector<int > m_nums;
    vector<Interval> m_intervals;
    class comp{
        public:
        bool operator()(Interval i1,int val){
            return i1.start<val;
        }
    };
    class comp2{
        public:
        bool operator()(Interval i1,Interval i2){
            return i1.start<i2.start;
        }
    };
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
    	auto comp3 = [](Interval a, Interval b) { return a.start < b.start; };
    	
        if(m_intervals.empty()){
            m_intervals.push_back(Interval(val,val));
            return;
        }
 
        auto lower_it=lower_bound(m_intervals.begin(),m_intervals.end(),val,comp());
       // auto lower_it=lower_bound(m_intervals.begin(),m_intervals.end(),Interval(val,val),comp2());//注意comp()和comp2()的使用 
       //auto lower_it=lower_bound(m_intervals.begin(),m_intervals.end(),Interval(val,val),comp3);
        if((*lower_it).start==val) return;
        else{
            if(lower_it==m_intervals.begin()){
                if(val==lower_it->start) return;
                else if(val==lower_it->start-1) lower_it->start=val;
                else  m_intervals.insert(m_intervals.begin(),Interval(val,val));
            }
            
            
            else{
                auto lower_it_1=lower_it-1;
                if((*lower_it_1).end>=val) return;
                else{
                    if((*lower_it_1).end+1==val&&(*lower_it).start-1==val){
                        (*lower_it_1).end=(*lower_it).end;
                        m_intervals.erase(lower_it);
                    }else if((*lower_it_1).end+1==val){
                        (*lower_it_1).end=val;
                    }else if((*lower_it).start-1==val){
                        (*lower_it).start=val;
                    }else{
                        m_intervals.insert(lower_it,Interval(val,val));
                    }
                }
            }
        }
        
    }
    
    vector<Interval> getIntervals() {
        return m_intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
 
  //法2
class SummaryRanges {
public:
    void addNum(int val) {
        auto Cmp = [](Interval a, Interval b) { return a.start < b.start; };
        auto it = lower_bound(vec.begin(), vec.end(), Interval(val, val), Cmp);
        int start = val, end = val;
        if(it != vec.begin() && (it-1)->end+1 >= val) it--;
        while(it != vec.end() && val+1 >= it->start && val-1 <= it->end)
        {
            start = min(start, it->start);
            end = max(end, it->end);
            it = vec.erase(it);
        }
        vec.insert(it,Interval(start, end));
    }

    vector<Interval> getIntervals() {
        return vec;
    }
private:
    vector<Interval> vec;
};

 //法3
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    void addNum(int val) {
        auto it = st.lower_bound(Interval(val, val));
        int start = val, end = val;
        if(it != st.begin() && (--it)->end+1 < val) it++;
        while(it != st.end() && val+1 >= it->start && val-1 <= it->end)
        {
            start = min(start, it->start);
            end = max(end, it->end);
            it = st.erase(it);
        }
        st.insert(it,Interval(start, end));
    }

    vector<Interval> getIntervals() {
        vector<Interval> result;
        for(auto val: st) result.push_back(val);
        return result;
    }
private:
    struct Cmp{
        bool operator()(Interval a, Interval b){ return a.start < b.start; }
    };
    set<Interval, Cmp> st;
};
