/*Question:
Find Duplicate in Array
Asked in:  
Amazon
VMWare
Riverbed
Given a read only array of n + 1 integers between 1 and n,
 find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.
*/
int Solution::repeatedNumber(const vector<int> &A) {
    
    int i,xor1=0,xor2=1;
    for(i=0;i<A.size();i++)
    {
        xor1^=A[i];
    }
    int n=A.size();
    for(i=2;i<=(n-1);i++)
    {
        xor2^=i;
    }
    int repeat;
    repeat=xor1^xor2;
    return repeat;
}