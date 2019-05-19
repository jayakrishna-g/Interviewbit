/*Question:
3 Sum Zero
Asked in:  
Facebook
Google
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:

 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets. For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:
(-1, 0, 1)
(-1, -1, 2) */

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    sort(A.begin(),A.end());
    vector<vector<int>> ret;
    for(int i=0;i<A.size();i++)
    {
        int l=i+1,r=A.size()-1;
        while(l<r)
        {
            int sum=A[i]+A[l]+A[r];
            if(sum==0){
                vector<int> rt={A[i],A[l],A[r]};
                if(!binary_search(ret.begin(),ret.end(),rt))
                ret.push_back(rt);
            }
            if(sum>0)
            r--;
            else
            l++;
        }
    }
    return ret;
}
