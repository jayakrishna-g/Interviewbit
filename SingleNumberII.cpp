/*
Question:
Single Number II
Asked in:  
Google
Amazon
Given an array of integers, every element appears thrice except for one which occurs once.

Find that element which does not appear thrice.

Note: Your algorithm should have a linear runtime complexity.

Could you implement it without using extra memory?*/

int Solution::singleNumber(const vector<int> &A) {
    int ones=0,c;
    vector<int> a(32,0);
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<32;j++)
        {
            if((1<<j)&A[i])
            a[j]++;
        }
    }
    for(int i=0;i<32;i++)
    {
        ones|=((a[i]%3)<<i);
    }
    return ones;
}
