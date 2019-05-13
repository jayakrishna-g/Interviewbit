/*Question
First Missing Integer
Asked in:  
Model N
InMobi
Amazon
Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.*/
void foo(vector<int> &a)
{
    int j=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]<=0)
        {
            swap(a[i],a[j]);
            j++;
        }
    }
    a.erase(a.begin(),a.begin()+j);
}
int Solution::firstMissingPositive(vector<int> &A) {
    foo(A);
   // cout<<A.size()<<endl;
    for(int i:A)
    {
        if(abs(i)<=A.size())
        {
            //cout<<i<<endl;
            A[abs(i)-1]*=-1;
        }
    }
    for(int i=0;i<A.size();i++)
    {
        if(A[i]>0)
        return i+1;
    }
    return A.size()+1;
}
