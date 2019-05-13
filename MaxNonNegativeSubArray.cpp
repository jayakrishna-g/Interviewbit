/*Question
Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be continuous. 
That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. 
Sub-array A is greater than sub-array B if sum(A) > sum(B).
*/

vector<int> Solution::maxset(vector<int> &a) {
    long long  mans=0,can=0,n=a.size();
    
    vector<int>ans;
    vector<int> maxs;
    for(int i=0;i<n;i++)
    {
        if(a[i]<0)
        {
            if(can>mans)
            {
                maxs.clear();
                mans=can;
                maxs=ans;
            }
            else if(can==mans)
            {
                if(maxs.size()<ans.size())
                {
                    maxs.clear();
                    maxs=ans;
                }
            }
            ans.clear();
            can=0;
        }
        else
        {
            ans.push_back(a[i]);
            can+=a[i];
        }
    }
    if(can>mans)
    {
        maxs.clear();
        mans=can;
        maxs=ans;
    }
    else if(can==mans)
    {
        if(maxs.size()<ans.size())
        {
            maxs.clear();
            maxs=ans;
        }
    }
    if(maxs.size()>0)
    return maxs;
    return ans;
}
