/*Question:
Subset
Asked in:  
Amazon
Microsoft
Given a set of distinct integers, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]
Seen this question in a real interview before*/

vector<vector<int>> z;
void foo(vector<int> A,vector<int> ret,int i)
{
    if(i>=A.size())
    {
       // cout<<"i"<<endl;
        z.push_back(ret);
        return ;
    }
    foo(A,ret,i+1);
    ret.push_back(A[i]);
    foo(A,ret,i+1);
    ret.pop_back();
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(),A.end());
    vector<int> ret;
    z.clear();
    foo(A,ret,0);
    sort(z.begin(),z.end());
    return z;
}
