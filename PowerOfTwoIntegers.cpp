/*QUestion:
Power Of Two Integers
Asked in:  
Housing
Amazon
Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0. 
A and P both should be integers.*/


int Solution::isPower(int A) {
    if(A==1)
    return 1;
    int i=2;
    int lim=sqrt(A);
    while(i<=lim)
    {
        double num=log10(A);
        double denom=log10(i);
        int ans=num/denom;
       // cout<<i<<" "<<ans<<" "<<ans*denom<<" "<<num<<endl;
        if(abs(ans*denom-num)<=0.0000001)
        return 1;
        i++;
    }
    return 0;
}
