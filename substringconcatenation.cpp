/*Question:
Substring Concatenation
Asked in:  
Facebook
You are given a string, S, and a list of words, L, that are all of the same length.

Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

Example :

S: "barfoothefoobarman"
L: ["foo", "bar"]
You should return the indices: [0,9].
(order does not matter).*/


vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    map<string ,int > m;
    //cout<<A<<endl;
    vector<int> ret;
    for(int i=0;i<B.size();i++)
    {
        m[B[i]]=m[B[i]]+1;
    }
    int lim=B.size()*B[0].size();
    for(int i=0;i+lim<A.size()+1;i++)
    {
        int flag=0;
        string s="";
        map<string,int> foo;
        for(int k=0;k<lim;k++)
        {
            s+=A[i+k];
        }
        for(int h=0;h<lim;)
        {
            string s1="";
            for(int d=0;d<B[0].size();d++,h++)
            {
                s1+=s[h];
            }
            foo[s1]=foo[s1]+1;
        }
        for(auto i0=foo.begin();i0!=foo.end();i0++)
        {
            if(i0->second > m[i0->first]){
            flag=1;
            break;
            }
        }
        if(!flag)
        {
            ret.push_back(i);
        }
    }
    return ret;
}
