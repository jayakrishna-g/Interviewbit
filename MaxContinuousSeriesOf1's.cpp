/*Question:
Max Continuous Series of 1s
Asked in:  
VMWare
You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.*/

vector<int> Solution::maxone(vector<int> &A, int B) {
    int s=0,e=0;
    int cz=0;
    int ans=0;
    int si=0,ei=0;
    int co=0;
    while(s<A.size(),e<A.size())
    {
        if(cz<=B)
        {
            if(A[e]==0)
            cz++;
            e++;
           
        }
        if(cz>B)
        {
            if(A[s]==0)
            cz--;
            s++;
            if(s>e)
            e=s;
        }
        if(ans<e-s+1)
        {
            ans=e-s+1;
            si=s;
            ei=e;
        }
    }
    vector<int> v;
    for(int i=si;i<ei;i++)
    v.push_back(i);
    return v;
}
