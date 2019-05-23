/*Question:
Permutations
Asked in:  
Microsoft
Adobe
Google
Given a collection of numbers, return all possible permutations.

Example:

[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]
 NOTE
No two entries in the permutation sequence should be the same.
For the purpose of this problem, assume that all the numbers in the collection are unique.*/


vector<vector<int>> ret;
void foo(vector<int> &A,int si,int ei)
{
    if(si>ei)
    {
        ret.push_back(A);
        return ;
    }
    for(int i=si;i<=ei;i++)
    {
        swap(A[si],A[i]);
        foo(A,si+1,ei);
        swap(A[si],A[i]);
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    ret.clear();
    int si=0,ei=A.size()-1;
    foo(A,si,ei);
    return ret;
}
