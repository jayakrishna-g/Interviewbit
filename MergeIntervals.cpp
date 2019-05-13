/*Question:
Merge Intervals
Asked in:  
Google
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:

Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Make sure the returned intervals are also sorted*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    int i=0;
    for(;i<intervals.size();i++)
    {
        if(intervals[i].start>newInterval.start)
        {
            break;
        }
    }
    //i--;
    //cout<<i<<endl;
    auto it=intervals.begin();
    while(i--)
    it++;
    intervals.insert(it,1,newInterval);
    /*for(Interval s:intervals)
    cout<<s.start<<" "<<s.end<<endl;*/
    vector<Interval> v;
    int j=0,k=0;
    int s=intervals[0].start;
    int e=intervals[0].end;
    for(j=0;j<intervals.size();j++)
    {
        if(intervals[j].start>e){
        v.push_back(Interval(s,e));
        s=intervals[j].start;
        e=intervals[j].end;
        }
        else
        {
            e=max(e,intervals[j].end);
        }
    }
    v.push_back(Interval(s,e));
    return v;
}
