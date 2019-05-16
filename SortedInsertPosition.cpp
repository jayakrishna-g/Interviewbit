/*Question:
Sorted Insert Position
Asked in:  
Yahoo
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.
*/

int Solution::searchInsert(vector<int> &A, int B) {
    int lo=0,hi=A.size()-1;
    if(A[hi]<B)
    return A.size();
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(A[mid]==B)
        return mid;
        else if(A[mid]<B&&A[mid+1]>B)
        return mid+1;
        else if(A[mid]<B)
        lo=mid+1;
        else
        hi=mid-1;
    }
}
