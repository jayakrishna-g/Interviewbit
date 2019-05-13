/*
QUestion
Prime Sum
Asked in:  
Epic systems
Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.

NOTE A solution will always exist. read Goldbach’s conjecture*/

bool* foo(int n)
{
    bool *prime=new bool[n+1];
    for(int i=0;i<n;i++)
    prime[i]=1;
    prime[1]=false;
    for(int i=2;i*i<=n;i++)
    {
        if(prime[i])
        {
            for(int j=i*i;j<=n;j+=i){
            prime[j]=false;}
        }
    }
    return prime;
}
vector<int> Solution::primesum(int A) {
    bool* prime=foo(A);
    vector<int >ans;
    int i=2;
    //cout<<prime[3]<<" ";
    while(1)
    {
        //cout<<i<<" "<<A-i<<" "<<prime[i]<<" "<<prime[A-i]<<endl;
        if(prime[i]&&prime[A-i])
        {
            ans.push_back(i);
            ans.push_back(A-i);
            return ans;
        }
        i++;
    }
    return ans;
}
