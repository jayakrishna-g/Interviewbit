/*
Question:
Reverse Integer
Reverse integer
Asked in:  
HCL
Bloomberg
Reverse digits of an integer.

Example1:

x = 123,

return 321
Example2:

x = -123,

return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer*/

int Solution::reverse(int A) {
    long long rev=0;
    int flag=0;
    if(A<0)
    {
        flag=1;
        A*=-1;
    }
    while(A>0)
    {
        rev=rev*10+(A%10);
        A=A/10;
    }
    if(rev>INT_MAX||rev<INT_MIN)
    return 0;
    if(flag)
    return -1*rev;
    return rev;
}
