/*Question:
NQueens
Asked in:  
Qualcomm
Google
Amazon
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

N Queens: Example 1

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]*/


int sol[1000][1000];
int n;
bool issafe(int ri, int ci)
{
    if(ri>=n||ci>=n)
    return false;
    int a=ri,b=ci;
    for(int i=0;i<n;i++)
    {
        if(sol[a][i]!=0)
        return false;
    }
    for(int j=0;j<n;j++)
    {
        if(sol[j][b]!=0)
        return false;
    }
    a=ri;b=ci;
    while(a>=0&&b>=0)
    {
        if(sol[a][b]!=0)
        return false;
        a--;b--;
    }
    a=ri;b=ci;
    while(a<n&&b<n)
    {
        if(sol[a][b]!=0)
        return false;
        a++;b++;
    }
    a=ri;b=ci;
    while(a>=0&&b<n)
    {
        if(sol[a][b]!=0)
        return false;
        a--;b++;
    }
    a=ri;b=ci;
    while(a<n&&b>=0)
    {
        if(sol[a][b]!=0)
        return false;
        a++;b--;
    }
    return true;
}
vector<vector<string>> ret;
void foo(int ri, int ci, int k)
{
    //cout<<k<<" ";
    if (k == n )
    {
       
        vector<string> v;
        for(int i=0;i<n;i++)
        {
            string s;
            for(int j=0;j<n;j++)
            {
                if(sol[i][j]==1)
                s.push_back('Q');
                else
                s.push_back('.');
                //cout<<s[j]<<" ";
            }
            //cout<<endl;
            v.push_back(s);
        }
        ret.push_back(v);
        return ;
    }
    for (int i = 0; i < n; i++)
    {
        if (issafe(ri , i))
        {
            sol[ri][i] = 1;
            foo(ri + 1, 0, k + 1);
            sol[ri][i] = 0;
        }
    }
}
vector<vector<string> > Solution::solveNQueens(int A) {
    
    memset(sol,0,sizeof(sol));
     n=A;
    ret.clear();
    if(A==1)
    {
        ret.push_back({"Q"});
        return ret;
    }
    foo(0,0,0);
    sort(ret.begin(),ret.end());
    return ret;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
