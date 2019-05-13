/* question:
MAXSPPROD
You are given an array A containing N integers. The special product of each ith integer in this array is defined as the product of the following:<ul>

LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (i>j). If multiple A[j]’s are present in multiple positions, the LeftSpecialValue is the maximum value of j. 

RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (j>i). If multiple A[j]s are present in multiple positions, the RightSpecialValue is the minimum value of j.

Write a program to find the maximum special product of any integer in the array.

Input: You will receive array of integers as argument to function.

Return: Maximum special product of any integer in the array modulo 1000000007.

Note: If j does not exist, the LeftSpecialValue and RightSpecialValue are considered to be 0.

Constraints 1 <= N <= 10^5 1 <= A[i] <= 10^9

Seen this question in a real interview beforeYesNo

*/
vector<long> leftgreater(vector<int> A)
{
    vector<long> ret(A.size(),0);
    stack<long> maxe;
    for(int i=0;i<A.size();i++)
    {
        while(!maxe.empty()&&A[i]>A[maxe.top()])
        {
            int r=maxe.top();
            maxe.pop();
            ret[r]=i;
        }
        maxe.push(i);
    }
    return ret;
}
vector<long> rightgreater(vector<int> A)
{
   
    vector<long> ret(A.size(),0);
    stack<long> maxe;
    for(int i=A.size()-1;i>=0;i--)
    {
        while(!maxe.empty()&&A[i]>A[maxe.top()])
        {
            int r=maxe.top();
            maxe.pop();
            ret[r]=i;
        }
        maxe.push(i);
    }
    return ret;
}
int Solution::maxSpecialProduct(vector<int> &A) {
    vector<long> l=leftgreater(A);
    vector<long> r=rightgreater(A);
    long ret=0,mod=1000000007;
    for(int i=0;i<A.size();i++)
    {
        ret=max(ret,l[i]*r[i]);
        ret=ret%mod;
    }
    return ret;
}
