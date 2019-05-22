/*Question:
Noble Integer
Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p
If such an integer is found return 1 else return -1.*/

int Solution::solve(vector<int> &A) {
    sort(A.begin(),A.end());
    int s=A.size();
    int count=0;
    for(auto i=0;i!=A.size()-1;i++)
    {
        
        
        if(A[i]==A[i+1])
        continue;
        count++;
        if(A[i]==(s-i-1)){
        //cout<<i<<")"<<s-count<<" "<<A[i]<<",";
        return 1;}
    }
    if(A[A.size()-1]==0)
    return 1;
    return -1;
}
