/*Question:
Remove Duplicates From Sorted Array Ii
Remove Duplicates from Sorted Array II
Asked in:  
Expedia
Microsoft
Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

Note that even though we want you to return the new length, make sure to change the original array as well in place

For example,
Given input array A = [1,1,1,2],

Your function should return length = 3, and A is now [1,1,2].*/

int Solution::removeDuplicates(vector<int> &A) {
    int count=0,j=0,cv=A[0];
    A[j++]=A[0];
    count++;
    for(int i=1;i<A.size();i++)
    {
        if(cv!=A[i])
        {
            count=1;
            A[j++]=A[i];
            cv=A[i];
        }
        else
        {
            if(count<2)
            {
                A[j++]=A[i];
                count++;
            }
        }
    }
    return j;
}
