/*
Question:
Minimize the absolute difference
Asked in:  
Microsoft
Problem Setter: ganeshk2 Problem Tester: dhruvi
Given three sorted arrays A, B and Cof not necessarily same sizes.

Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.
i.e. minimize | max(a,b,c) - min(a,b,c) |.*/

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int diff,fi=A.size()-1,si=B.size()-1,ti=C.size()-1,ans=INT_MAX;
    while(fi>=0&&si>=0&&ti>=0)
    {
        int maxi=max(A[fi],max(B[si],C[ti]));
        int mini=min(A[fi],min(B[si],C[ti]));
        cout<<ans<<endl;
        diff=maxi-mini;
        ans=min(ans,diff);
        if(maxi==A[fi])
        fi--;
        else if(maxi==B[si])
        si--;
        else
        ti--;
    }
    return ans;
}
