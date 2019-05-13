/*Question:
Trailing Zeros in Factorial
Asked in:  
Microsoft
Jabong
Zillow
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.*/
int Solution::trailingZeroes(int A) {
    int count=0;
    for(int i=5;A/i>=1;i*=5)
    {
        count+=A/i;
    }
    return count;
}
