/*
Question:
Combination Sum
Asked in:  
Facebook
Amazon
Adobe
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The combinations themselves must be sorted in ascending order.
CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR … (a1 = b1 AND a2 = b2 AND … ai = bi AND ai+1 > bi+1)
The solution set must not contain duplicate combinations.
Example, 
Given candidate set 2,3,6,7 and target 7,
A solution set is:

[2, 2, 3]
[7]
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
Example : itertools.combinations in python.
If you do, we will disqualify your submission retroactively and give you penalty points.*/

vector<vector<int>> ret;
void foo(vector<int> A,int b,int i,vector<int> an,int sum)
{
    if(i>=A.size())
    {
        if(sum==b)
        {
            sort(an.begin(),an.end());
            //if(!binary_search(ret.begin(),ret.end(),an))
            ret.push_back(an);
        }
        return ;
    }
    if(sum==b)
    {
        sort(an.begin(),an.end());
        //if(!binary_search(ret.begin(),ret.end(),an))
        ret.push_back(an);
        return ;
    }
    else if(sum>b||sum<0)
    return ;
    else
    {
        an.push_back(A[i]);
        foo(A,b,i,an,sum+A[i]);
        an.pop_back();
        foo(A,b,i+1,an,sum);
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    ret.clear();
    vector<int> an;
    vector<int> inpt;
    sort(A.begin(),A.end());
    for(int i=0;i<A.size()-1;i++)//remove duplicates
    {
        if(A[i]!=A[i+1])
        inpt.push_back(A[i]);
    }
    inpt.push_back(A[A.size()-1]);
    foo(inpt,B,0,an,0);
    sort(ret.begin(),ret.end());
    return ret;
}
