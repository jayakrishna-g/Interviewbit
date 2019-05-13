/*Question:
Largest Number
Asked in:  
Amazon
Goldman Sachs
Microsoft
Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/
bool cmp(string a,string b)
    {
        string a1=a.append(b);
        string b1=b.append(a);
        return a1>b1;
    }
string Solution::largestNumber(const vector<int> &A) {
    vector<string> s;
    for(int i=0;i<A.size();i++)
    {
        s.push_back(to_string(A[i]));
    }
    
    sort(s.begin(),s.end(),cmp);
    
    string ans="";
    for(string a:s)
    ans+=a;
    string fans="";
    if(ans[0]=='0')
    {
        int i=0;
        for(;i<ans.size();i++)
        {
            if(ans[i]!='0')
            break;
        }
        for(;i<ans.size();i++)
        fans+=ans[i];
        if(fans=="")
        return "0";
        return fans;
    }
    return ans;
}
