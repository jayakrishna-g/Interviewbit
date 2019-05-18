/*Question:
Remove duplicates from Sorted Array
Given a sorted array, remove the duplicates in place such that each element appears only once and return the new length.

Note that even though we want you to return the new length, make sure to change the original array as well in place

Do not allocate extra space for another array, you must do this in place with constant memory.*/

int Solution::removeDuplicates(vector<int> &A) {
    int j=0,i=0;
    for(i=0;i<A.size()-1;i++)
    {
        if(A[i]==A[i+1])
        continue;
        A[j++]=A[i];
    }
    A[j++]=A[i];
    return j;
}
