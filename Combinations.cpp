/*Question:
Combinations
Asked in:  
Amazon
Adobe
Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,

Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
Entries should be sorted within themselves.
Example :
If n = 4 and k = 2, a solution is:

[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
Example : itertools.combinations in python.
If you do, we will disqualify your submission retroactively and give you penalty points. 
*/

vector<vector<int>> ret;
void foo(int a,int b,int i,vector<int> as)
{
    if(i>a)
    {
        if(b==0){
        sort(as.begin(),as.end());
        ret.push_back(as);
        }
        return;
    }
    if(b==0)
    foo(a,b,i+1,as);
    else
    {
        foo(a,b,i+1,as);
        as.push_back(i);
        foo(a,b-1,i+1,as);
        as.pop_back();
    }
}
vector<vector<int> > Solution::combine(int A, int B) {
    ret.clear();
    vector<int> as;
    foo(A,B,1,as);
    sort(ret.begin(),ret.end());
    return ret;
}
