/*
QUestion:
Reverse Bits
Asked in:  
Nvidia
HCL
Amazon
Reverse bits of an 32 bit unsigned integer

Example 1:

x = 0,

          00000000000000000000000000000000  
=>        00000000000000000000000000000000
return 0

Example 2:

x = 3,

          00000000000000000000000000000011 
=>        11000000000000000000000000000000
return 3221225472
*/

unsigned int Solution::reverse(unsigned int A) {
    vector<int> a(32,0);
    int i=0;
    while(A>0)
    {
        a[i]=(A%2);
        A/=2;
        i++;
    }
    unsigned int ret=0;
    int j=0;
    for(i=31;i>=0;i--)
    {
        ret+=(a[i]*pow(2,j));
        j++;
    }
    return ret;
}
