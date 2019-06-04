/*Gray Code
Asked in:  
Microsoft
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
There might be multiple gray code sequences possible for a given n.
Return any such sequence.
*/

int rev(int num,int no)
{
    int ret=0;
    for(int i=0;i<no;i++)
    {
        ret|=(num&(1<<i));
        ret>>1;
    }
    return ret;
}
vector<int> foo(int ai)
{
    if(ai==1)
    {
        return {0,1};
    }
    vector<int> r=foo(ai-1);
    int offset=1<<(ai-1);
    for(int i=r.size()-1;i>=0;i--)
    {
        r.push_back(rev(r[i],ai-1)|offset);
    }
    return r;
}
vector<int> Solution::grayCode(int A) {
    return foo(A);
}

