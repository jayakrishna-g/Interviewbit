/*question:
Square Root of Integer
Asked in:  
Facebook
Amazon
Microsoft
Implement int sqrt(int x).

Compute and return the square root of x.

If x is not a perfect square, return floor(sqrt(x))*/

int Solution::sqrt(int A) {
    if(A==0||A==1)
    return A;
    int x=1,y=A/2;
    while(x<=y)
    {
        long long mid=(x+y)/2;
        long long foo=mid*mid;
        if(foo==A)
        return mid;
        if(foo<A)
        x=mid+1;
        else
        y=mid-1;
    }
    return x-1;
}
