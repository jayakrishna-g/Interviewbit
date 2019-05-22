/*Question:
Sum of pairwise Hamming Distance
Asked in:  
Google
Problem Setter: yashpal1995 Problem Tester: amitkgupta94
Hamming distance between two non-negative integers is defined as the number of positions at which the corresponding bits are different.

For example,

HammingDistance(2, 7) = 2, as only the first and the third bit differs in the binary representation of 2 (010) and 7 (111).

Given an array of N non-negative integers, find the sum of hamming distances of all pairs of integers in the array.
Return the answer modulo 1000000007.*/
//O(n):
int foo(int a,int b)
{
    int c=a^b;
    return 2*__builtin_popcount(c);
}
int Solution::hammingDistance(const vector<int> &A) {
    long ans=0,mod=1000000007;
    for(int i=0;i<32;i++)
    {
        int count=0;
       for(int j=0;j<A.size();j++)
       {
           if(A[j]&(1<<i))
           count++;
       }
       ans=((ans%mod)+(((count%mod)*(((A.size()%mod-count%mod)%mod)*2)%mod)%mod))%mod;
    }
    return ans%mod;
}



//O(n^2):
int foo(int a,int b)
{
    int c=a^b;
    return 2*__builtin_popcount(c);
}
int Solution::hammingDistance(const vector<int> &A) {
    long ans=0,mod=1000000007;
    for(int i=0;i<A.size();i++)
    {
        for(int j=i;j<A.size();j++)
        {
            ans=(ans%mod+foo(A[i],A[j])%mod)%mod;
        }
    }
    return ans%mod;
}
