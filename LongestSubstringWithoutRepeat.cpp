/*
Question:
Longest Substring Without Repeat
Asked in:  
Amazon
Given a string, 
find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.*/

int los(string s)
{
    string temp="";
    int maxi=0;
    int t=1,ep=1;
    map<char,int> m;
    for(int i=0;i<s.size();i++)
    m[s[i]]=-1;
    t=1;
    m[s[0]]=0;
    for(int i=1;i<s.size();i++)
    {
        if(m[s[i]]!=-1 and i-t<=m[s[i]])
        {
            t=i-m[s[i]];
        }
        else
        {
            t++;
        }
        m[s[i]]=i;
        //cout<<t<<endl;
        maxi=max(maxi,t);
    }
    return maxi;
}
int Solution::lengthOfLongestSubstring(string A) {
    if(A.size()==1)
    return 1;
    else
    return los(A);
}
