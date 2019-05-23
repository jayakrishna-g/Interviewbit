/*Question:
Letter Phone
Asked in:  
Facebook
Epic systems
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



The digit 0 maps to 0 itself.
The digit 1 maps to 1 itself.

Input: Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Make sure the returned strings are lexicographically sorted.*/

map<char ,string> m;
void foo()
{
    m['0']="0";
    m['1']="1";
    m['2']="abc";
    m['3']="def";
    m['4']="ghi";
    m['5']="jkl";
    m['6']="mno";
    m['7']="pqrs";
    m['8']="tuv";
    m['9']="wxyz";
}
vector<string> ret;
void foo(string A,int i,string ans)
{
    if(i>=A.size())
    {
        if(ans!="")
        ret.push_back(ans);
        return ;
    }
    string temp=m[A[i]];
    //cout<<temp<<endl;
    for(int j=0;j<temp.size();j++)
    {
        foo(A,i+1,ans+temp[j]);
    }
}
vector<string> Solution::letterCombinations(string A) {
    foo();
    ret.clear();
    string ans="";
    foo(A,0,ans);
    sort(ret.begin(),ret.end());
    return ret;
}
