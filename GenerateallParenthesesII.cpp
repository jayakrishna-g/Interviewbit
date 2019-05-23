/*
Question:
Generate all Parentheses II
Asked in:  
Facebook
Microsoft
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
Make sure the returned list of strings are sorted.*/

vector<string> ret;
void foo(int A,string ans,int o,int e)
{
    if(o==A&&e==A)
    {
        ret.push_back(ans);
        return ;
    }
    if(o==0||o==e)
    {
        foo(A,ans+"(",o+1,e);
        return ;
    }
    if(o==A)
    {
        foo(A,ans+")",o,e+1);
        return ;
    }
    foo(A,ans+"(",o+1,e);
    foo(A,ans+")",o,e+1);
}
vector<string> Solution::generateParenthesis(int A) {
    ret.clear();
    string ans="";
    foo(A,ans,0,0);
    sort(ret.begin(),ret.end());
    return ret;
}
