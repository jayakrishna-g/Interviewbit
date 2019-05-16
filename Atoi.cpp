/*Question:
Atoi
Asked in:Adobe,Nvidia ,Agilent systems ,Bloomberg ,Amazon, Apple, Microsoft ,Groupon.
Implement atoi to convert a string to an integer.*/

int Solution::atoi(const string A) {
    string number="";
    bool negative=false;
    int i=0;
    while(A[i]==' ')i++;
    if(A[i]=='-')
    {
        negative=true;
        i++;
    }
    if(A[i]=='+')
    {
        negative=false;
        i++;
    }
    while('0'<=A[i]&&A[i]<='9')
    {
        number+=A[i];
        i++;
    }
    if(number.size()>=10)
    {
        if(negative)
        return INT_MIN;
        else
        return INT_MAX;
    }
    long ans=0;
    for(int j=0;j<number.size();j++)
    {
        ans=ans*10+(number[j]-'0');
    }
    if(negative)
    {
        ans*=-1;
        if(ans<INT_MIN)
        return INT_MIN;
        return ans;
    }
    else
    {
        if(ans<INT_MAX)
        return ans;
        return INT_MAX;
    }
}
