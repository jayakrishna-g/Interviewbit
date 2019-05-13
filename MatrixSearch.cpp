/* Question:
Write an efficient algorithm that searches for a value in an m x n matrix.

This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than or equal to the last integer of the previous row.
Example:

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return 1 ( 1 corresponds to true )

Return 0 / 1 ( 0 if the element is not present, 1 if the element is present ) for this problem*/


int bs(vector<int> v,int B)
{
    int lo=0;
    int hi=v.size()-1;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(v[mid]==B)
        return 1;
        else if(v[mid]>B)
        hi=mid-1;
        else
        lo=mid+1;
    }
    return 0;
}
int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int lo=0,hi=A.size()-1;
    int r;
    vector<int> lastro=A[A.size()-1];
    if(lastro[0]<=B)
    {
        return bs(lastro,B);
    }
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(A[mid][0]<=B&&A[mid+1][0]>B)
        {
            r=mid;
            break;
        }
        else if(A[mid][0]>=B)
        hi=mid-1;
        else
        lo=mid+1;
    }
    lastro=A[r];
    return bs(lastro,B);
}
