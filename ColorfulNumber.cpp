/*QUestion:
Colorful Number
Asked in:  
Epic systems
For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1
*/

int Solution::colorful(int A) {
    vector<int> vec;
    while(A>0)
    {
        vec.push_back(A%10);
        A=A/10;
    }
    set<long long> s;
    int value;
    for(int i=0;i<vec.size();i++)
    {
        for(int j=i;j<vec.size();j++)
        {
            long long pro=1;
            for(int k=i;k<=j;k++)
            {
                pro=pro*vec[k];
            }
            if(s.find(pro)!=s.end())
            return 0;
            s.insert(pro);
        }
    }
    return 1;
}

