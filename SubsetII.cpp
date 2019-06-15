/*QUestion:
Subsets II
Asked in:  
Amazon
Microsoft
Given a collection of integers that might contain duplicates, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.
Example :
If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
] */

vector<vector<int>> z;
void foo(vector<int> A,vector<int> ret,int i)
{
    if(i>=A.size())
    {
       // cout<<"i"<<endl;
       if(find(z.begin(),z.end(),ret)==z.end())
        z.push_back(ret);
        return ;
    }
    foo(A,ret,i+1);
    ret.push_back(A[i]);
    foo(A,ret,i+1);
    ret.pop_back();
}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    sort(A.begin(),A.end());
    vector<int> ret;
    z.clear();
    foo(A,ret,0);
    sort(z.begin(),z.end());
    return z;
}
