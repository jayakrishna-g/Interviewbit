/*
Question:
Single Number
Asked in:  
Amazon
Given an array of integers, every element appears twice except for one. Find that single one.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?*/

int Solution::singleNumber(const vector<int> &A) {
    int xorq=0;
    for(int i=0;i<A.size();i++)
    xorq=xorq^A[i];
    return xorq;
}
