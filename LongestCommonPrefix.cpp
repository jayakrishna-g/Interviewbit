/*Question:
Longest Common Prefix
Asked in:  
Google
Write a function to find the longest common prefix string amongst an array of strings.

Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.

As an example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".

Given the array of strings, you need to find the longest S which is the prefix of ALL the strings in the array.*/

string Solution::longestCommonPrefix(vector<string> &A) {
    string ans=A[0];
    for(int i=0;i<A.size();i++)
    {
        string req=A[i];
        int j=0;
        for(j=0;j<ans.size(),ans[j]!='\0',j<req.size();j++)
        {
            if(req[j]!=ans[j])
            {
                ans[j]='\0';
                break;
            }
        }
        if(j!=ans.size())
        ans[j]='\0';
    }
    string ret="";
    for(int i=0;ans[i]!='\0';i++)
    ret+=ans[i];
    return ret;
}
