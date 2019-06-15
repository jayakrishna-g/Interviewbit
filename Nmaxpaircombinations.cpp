/*
Question:
N max pair combinations
Asked in:  
Liv.ai
Problem Setter: dhruvi Problem Tester: ganeshk2
Given two arrays A & B of size N each.
Find the maximum N elements from the sum combinations (Ai + Bj) formed from elements in array A and B.

For example if A = [1,2], B = [3,4], then possible pair sums can be 1+3 = 4 , 1+4=5 , 2+3=5 , 2+4=6
and maximum 2 elements are 6, 5

Example:

N = 4
a[]={1,4,2,3}
b[]={2,5,1,6}

Maximum 4 elements of combinations sum are
10   (4+6), 
9    (3+6),
9    (4+5),
8    (2+6)
Seen this question in a real interview before
 */

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    vector<int> ret;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    priority_queue < pair<int , pair <int,int> > >q;
    map<pair<int,int> , int> m;
    q.push(make_pair(A[A.size()-1]+B[B.size()-1],make_pair(A.size()-1,B.size()-1)));
    m[make_pair(A.size()-1,B.size()-1)]=1;
    while(ret.size()<A.size())
    {
        pair<int ,pair<int,int>> p=q.top();
        q.pop();
        ret.push_back(p.first);
        pair<int,int> np1=make_pair(p.second.first-1,p.second.second);
        pair<int,int> np2=make_pair(p.second.first,p.second.second-1);
        if(m[np1]!=1)
        {
            m[np1]=1;
            q.push(make_pair(A[np1.first]+B[np1.second],np1));
        }
        if(m[np2]!=1)
        {
            m[np2]=1;
            q.push(make_pair(A[np2.first]+B[np2.second],np2));
        }
    }
    return ret;
}
