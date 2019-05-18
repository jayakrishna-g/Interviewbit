/*Min XOR value
Asked in:  
Booking.com
Problem Setter: mihai.gheorghe Problem Tester: archit.rai
Given an array of N integers, find the pair of integers in the array which have minimum XOR value. Report the minimum XOR value.

Examples : 
Input 
0 2 5 7 
Output 
2 (0 XOR 2) 
Input 
0 4 7 9 
Output 
3 (4 XOR 7)

Constraints: 
2 <= N <= 100 000 
0 <= A[i] <= 1 000 000 000

Seen this question in a real interview before*/

int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(),A.end());
    int minxor=1000000;
    for(int i=0;i<A.size()-1;i++)
    {
        minxor=min(minxor,A[i]^A[i+1]);
    }
    return minxor;
}
