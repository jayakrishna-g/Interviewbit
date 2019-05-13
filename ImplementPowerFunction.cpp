/*
Question:Implement Power Function
Asked in:  
Google
LinkedIn
Implement pow(x, n) % d.

In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative. 
In other words, make sure the answer you return is non negative.
long long foo(int x,int n,int d)*/
{
    if(n==0)
    return 1;
    if(n==1)
    return x%d;
    long long ans,ret;
    ans=foo(x,n/2,d);
    if(n%2!=0)
    {
        ret=(ans%d*ans%d*x%d)%d;
    }
    if(n%2==0)
    {
        ret=(ans%d*ans%d)%d;
    }
    return ret%d;
}
int Solution::pow(int x, int n, int d) {
    if(x==0||x==1)
    return x;
    long long  ret=foo(x,n,d);
    return ((ret%d)+d)%d;
}
