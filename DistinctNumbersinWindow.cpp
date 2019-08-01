/*
Question:
Distinct Numbers in Window
Asked in:  
Amazon
You are given an array of N integers, A1, A2 ,…, AN and an integer K. Return the of count of distinct numbers in all windows of size K.

Formally, return an array of size N-K+1 where i’th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,…, Ai+k-1.

Note:

If K > N, return empty array.
For example,

A=[1, 2, 1, 3, 4, 3] and K = 3

All windows of size K are

[1, 2, 1]
[2, 1, 3]
[1, 3, 4]
[3, 4, 3]

So, we return an array [2, 3, 3, 2].
Seen this question in a real interview before
 */

vector<int> Solution::dNums(vector<int> &A, int B) {
    if(B>A.size())
    return {};
    vector<int> ret;
    map<int,int> m;
    int i=0,count=0;
    for(;i<B;i++)
    {
        if(m[A[i]]==0)
        count++;
        m[A[i]]+=1;
    }
    ret.push_back(count);
    for(;i<A.size();i++)
    {
        if(m[A[i-B]]==1)
        count--;
        m[A[i-B]]-=1;
        if(m[A[i]]==0)
        count++;
        m[A[i]]+=1;
        ret.push_back(count);
    }
    return ret;
}
