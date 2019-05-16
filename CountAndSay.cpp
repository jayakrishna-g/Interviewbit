/*Question:
Count And Say
Asked in:  
Facebook
The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2,
the sequence is 11.
*/

string Solution::countAndSay(int A) {
    string req="1";
    string ans="";
    if(A==0)
    return ans;
    A--;
    while(A--)
    {
        int len=req.size();
        int i,count=1;        //cout<<req<<endl;
        for(i=0;i<len;i++)
        {
           if(i+1<len,req[i]==req[i+1])
           {
               count++;
           }
           else
           {
                ans+=to_string(count);
                ans+=req[i];
                count=1;
           }
        }
        req=ans;
        ans.clear();
    }
    return req;
}
