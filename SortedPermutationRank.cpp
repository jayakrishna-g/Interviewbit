/*Question:
Sorted Permutation Rank
Asked in:  
Housing
Zenefits
Microsoft
Given a string, find the rank of the string amongst its permutations sorted lexicographically. 
Assume that no characters are repeated.*/
int* returnfact(int n,int m)
{
    int *a=new int[n+1];
    int w=1;
    for(int i=1;i<=n;i++)
    {
        w=((w%m)*(i%m))%m;
        a[i]=w;
    }
    return a;
}
int Solution::findRank(string b) {
    int *a=new int[256];
    for(int i=0;i<256;i++)
    a[i]=0;
    for(int i=0;i<b.size();i++)
    {
        a[b[i]]++;
    }
    int ans=0;
    int count=0;
    int mod=1000003;
    int *fact=returnfact(b.size(),mod);
    for(int i=0;i<b.size();i++)
    {
        int lim=b[i];
        count=0;
        for(int i=0;i<lim;i++)
        {
            count+=a[i];
        }
        ans=(ans%mod+(count*fact[b.size()-i-1])%mod)%mod;
        count=0;
        a[lim]--;
        //cout<<ans;
    }
    return ans+1;
}