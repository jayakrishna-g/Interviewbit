/*Question:
Amazing Subarrays
You are given a string S, and you have to find all the amazing substrings of S.

Amazing Substring is one that starts with a vowel (a, e, i, o, u, A, E, I, O, U).

Input

Only argument given is string S.
Output

Return a single integer X mod 10003, here X is number of Amazing Substrings in given string.
*/

bool foo(char ch)
{
    return ch=='A'||ch=='a'||ch=='E'||ch=='e'||ch=='I'||ch=='i'||ch=='o'||ch=='O'||ch=='u'||ch=='U';
}
int Solution::solve(string A) {
    int ans=0;
    int mod=10003;
    int count=0;
    for(int i=0;i<A.size();i++)
    {
        if(foo(A[i]))
        {
            ans=(ans%mod+(A.size()-i)%mod)%mod;
        }
    }
    return ans%mod;
}
