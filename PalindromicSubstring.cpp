/*:
Question:
Longest Palindromic Substring
Asked in:  
Amazon
Microsoft
Groupon
Given a string S, find the longest palindromic substring in S.

Substring of string S:

S[i...j] where 0 <= i <= j < len(S)

Palindrome string:

A string which reads the same backwards. 
More formally, S is palindrome if reverse(S) = S.

Incase of conflict, return the substring which occurs first ( with the least starting index ).*/


//O(n^3) solution but still accepted space O(1)(without considering ret string)
int ispalindrome(string s,int i,int j)
{
    while(i<=j)
    {
        if(s[i]!=s[j])
        return 0;
        i++;
        j--;
    }
    return 1;
}
string Solution::longestPalindrome(string A) {
    int maxi=0;
    int maxj=0;
    int maxl=0;
    for(int i=0;i<A.size();i++)
    {
        for(int j=A.size()-1;j>=i;j--)
        {
            if(maxl<(j-i+1)&&ispalindrome(A,i,j))
            {
                maxl=j-i+1;
                maxi=i;
                maxj=j;
            }
        }
    }
    string ret="";
    for(int i=maxi;i<=maxj;i++)
    {
        ret+=A[i];
    }
    return ret;
}







//O(n^2) solution expected solution space O(1) (without considering ret string)

string Solution::longestPalindrome(string A) {
    int maxi=0;
    int maxj=0;
    int maxl=0;
    for(int i=0;i<A.size();i++)
    {
        int s,e;
        s=i-1;
        e=i;
        while(s>=0&&e<A.size()&&A[s]==A[e])
        {
            if(e-s+1>maxl)
            {
                maxi=s;
                maxj=e;
                maxl=e-s+1;
            }
            s--;
            e++;
        }
        s=i-1;
        e=i+1;
        while(s>=0&&e<A.size()&&A[s]==A[e])
        {
            if(e-s+1>maxl)
            {
                maxi=s;
                maxj=e;
                maxl=e-s+1;
            }
            s--;
            e++;
        }
    }
    string ret="";
    for(int i=maxi;i<=maxj;i++)
    {
        ret+=A[i];
    }
    return ret;
}
