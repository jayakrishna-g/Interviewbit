/*
Question:
Shortest Unique Prefix
Asked in:  
Google
Find shortest unique prefix to represent each word in the list.

Example:

Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov
 NOTE : Assume that no word is prefix of another. In other words, the representation is always possible
 */


struct trieNode
{
    int a[26];
    struct trieNode* link[26];
};
struct trieNode* nn()
{
    struct trieNode *n=new (struct trieNode);
    memset(n->a,0,sizeof(n->a));
    for(int i=0;i<26;i++)
    n->link[i]=NULL;
    return n;
}
void insert(struct trieNode* head,string s,int i)
{
    if(i==s.size())
    return ;
    head->a[s[i]-'a']++;
    if(head->a[s[i]-'a']==1){
    head->link[s[i]-'a']=nn();}
    insert(head->link[s[i]-'a'],s,i+1);
}
bool bar(struct trieNode *head)
{
    for(int i=0;i<26;i++)
    {
        if(head->a[i])
        return false;
    }
    return true;
}
void print(struct trieNode *head,string s)
{
    if(bar(head)){cout<<s<<endl;
    return ;}
    for(int i=0;i<26;i++)
    {
        if(head->a[i])
        {
            s.push_back((char)(i+'a'));
            print(head->link[i],s);
            s.pop_back();
        }
    }
}
string foo(struct trieNode*head,string s,string ret,int i)
{
    if(i==s.size())
    return ret;
    int count=0;
    for(int i=0;i<26;i++)
    {
        count+=head->a[i];
    }
    if(count==1)
    return ret;
    ret.push_back(s[i]);
    return foo(head->link[s[i]-'a'],s,ret,i+1);
}
vector<string> Solution::prefix(vector<string> &A) {
    struct trieNode *head=nn();
    for(int i=0;i<A.size();i++)
    {
        insert(head,A[i],0);
    }
    //print(head,"");
    vector<string> ret;
    for(int i=0;i<A.size();i++)
    {
        string z="";
        ret.push_back(foo(head,A[i],z,0));
    }
    return ret;
}
