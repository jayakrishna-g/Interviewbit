/*Question:
Grid Unique Paths
Asked in:  
Google
Amazon
Microsoft
Adobe
A robot is located at the top-left corner of an A x B grid (marked ‘Start’ in the diagram below).

Path Sum: Example 1

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).

How many possible unique paths are there?

Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.*/

int ncr(int n,int r)
{
    long long num=1,denom=1;
    for(int i=0;i<r;i++)
    {
        num*=(n-i);
        denom*=(r-i);
    }
    return num/denom;
}
int Solution::uniquePaths(int A, int B) {
    if(A==1||B==1)
    return 1;
    return ncr(A+B-2,A-1);
}
