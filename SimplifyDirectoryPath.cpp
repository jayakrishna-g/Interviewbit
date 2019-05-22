/*Question:
Simplify Directory Path
Asked in:  
Microsoft
Given an absolute path for a file (Unix-style), simplify it.

Examples:

path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
Note that absolute path always begin with ‘/’ ( root directory )
Path will not have whitespace characters.




NOTE: three consecutive dots are not allowed.



*/

string Solution::simplifyPath(string A) {
    stack<string> s;
    string t="";
    int count=0;
    for(int i=0;i<A.size();i++){
        if(A[i]=='/'){
            continue;
        }
        if(A[i]=='.'){
            if(i+1<A.size() && A[i+1]=='.'){
                if(!s.empty())
                    s.pop();
                i++;
            }
        }
        else{
            string tem="";
            while(i<A.size() && A[i]!='/'){
                tem = tem+A[i];
                i++;
            }
            s.push(tem);
        }
    }
    string ret="";
    while(!s.empty())
    {
        ret="/"+s.top()+ret;
        s.pop();
    }
    if(ret=="")
    return "/";
    return ret;
}
