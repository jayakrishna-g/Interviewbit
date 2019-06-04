/*Question:
Points on the Straight Line
Asked in:  
Google
Amazon
InMobi
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Sample Input :

(1, 1)
(2, 2)
Sample Output :

2
You will be given 2 arrays X and Y. Each point is represented by (X[i], Y[i])


*/





int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    int maxi=0;
    if(A.size()<=2)
    return A.size();
    for(int i=0;i<A.size();i++)
    {
        map<pair<int,int>,int> v;
        for(int j=0;j<A.size();j++)
        {
            if(i!=j){
                int y=B[j]-B[i];
                int x=A[j]-A[i];
                int hc=__gcd(x,y);
                if(hc==0)
                {
                    hc=1;
                }
                v[(make_pair(y/hc,x/hc))]+=1;
            }
        }
        for(auto i=v.begin();i!=v.end();i++)
        {
           // cout<<(i->first).first<<" "<<(i->first).second<<"  :"<<i->second<<endl;
            maxi=max(maxi,i->second+1);
        }
    }
    return maxi;
}
