/*Question:
Reverse the String
Asked in:  
Qualcomm
Amazon
Microsoft
Cisco
Facebook
Given an input string, reverse the string word by word.

Example:

Given s = "the sky is blue",

return "blue is sky the".

A sequence of non-space characters constitutes a word.
Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
If there are multiple spaces between words, reduce them to a single space in the reversed string.
Seen this question in a real interview before*/



void Solution::reverseWords(string &A) {
    string result="";
    stack <string> s;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==' '){
        s.push(result);
        result.clear();
        }
        else
        result+=A[i];
    }
    A.clear();
    while(!s.empty())
    {
        A+=s.top();
        A+=" ";
        s.pop();
    }
    return A;
}
