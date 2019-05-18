/*Question:
Number of 1 Bits
Asked in:  
Adobe
Yahoo
Write a function that takes an unsigned integer and returns the number of 1 bits it has.

Example:

The 32-bit integer 11 has binary representation

00000000000000000000000000001011
so the function should return 3.

Note that since Java does not have unsigned int, use long for Java*/

int Solution::numSetBits(unsigned int A) {
    int count=0;
    for(int i=0;i<=31;i++)
    {
        if(((1<<i)&A)!=0)
        count++;
    }
    //return __builtin_popcount(A);
    return count;
}
