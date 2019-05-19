/*
Question:
3 Sum
Asked in:  
Facebook
Amazon
Microsoft
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers.

Assume that there will only be one solution

Example: 
given array S = {-1 2 1 -4}, 
and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)

*/
int Solution::threeSumClosest(vector<int> &A, int B) {
    if(A.size()<3)
    return 0;
    sort(A.begin(),A.end());
    int ans=INT_MAX;
    int org=0;
    for(int i=0;i<A.size()-2;i++)
    {
        int l=i+1,r=A.size()-1;
        while(l<r)
        {
            int sum=A[i]+A[l]+A[r];
            if(sum==B)
            {
                //cout<<A[i]<<" "<<A[l]<<" "<<A[r]<<endl;
                return sum;
            }
            int dif=abs(B-sum);
            if(ans>dif){
            ans=dif;
            org=sum;
            }
            if(sum>B)
            r--;
            else
            l++;
        }
    }
    return org;
}
