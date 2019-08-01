/*
Question:

Hotel Reviews
Asked in:  
Booking.com
Problem Setter: ishubansal Problem Tester: raghav_aggiwal
Given a set of reviews provided by the customers for different hotels and a string containing “Good Words”, you need to sort the reviews in descending order according to their “Goodness Value” (Higher goodness value first). We define the “Goodness Value” of a string as the number of “Good Words” in that string.

Note: Sorting should be stable. If review i and review j have the same “Goodness Value” then their original order would be preserved.

 You are expected to use Trie in an Interview for such problems 

Constraints:

1.   1 <= No.of reviews <= 200
2.   1 <= No. of words in a review <= 1000
3.   1 <= Length of an individual review <= 10,000
4.   1 <= Number of Good Words <= 10,000
5.   1 <= Length of an individual Good Word <= 4
6.   All the alphabets are lower case (a - z)
Input:

S : A string S containing "Good Words" separated by  "_" character. (See example below)
R : A vector of strings containing Hotel Reviews. Review strings are also separated by "_" character.
Output:

A vector V of integer which contain the original indexes of the reviews in the sorted order of reviews. 

V[i] = k  means the review R[k] comes at i-th position in the sorted order. (See example below)
In simple words, V[i]=Original index of the review which comes at i-th position in the sorted order. (Indexing is 0 based)
Example:

Input: 
S = "cool_ice_wifi"
R = ["water_is_cool", "cold_ice_drink", "cool_wifi_speed"]

Output:
ans = [2, 0, 1]
Here, sorted reviews are ["cool_wifi_speed", "water_is_cool", "cold_ice_drink"]
 */

typedef struct n
{
    struct n* data[256];
    bool isend;
}node;
node* nn()
{
    node* n=new(node);
    for(int i=0;i<256;i++)
    n->data[i]=NULL;
    n->isend=false;
    return n;
}
void insert(node* head,string s,int i)
{
    if(i==s.size())
    {
        head->isend=true;
        return;
    }
    if(head->data[s[i]]==NULL)
    head->data[s[i]]=nn();
    head=head->data[s[i]];
    insert(head,s,i+1);
}
bool search(node* head,string s,int i)
{
    if(head==NULL)
    return false;
    if(i==s.size())
    {
        return head->isend;
    }
    return search(head->data[s[i]],s,i+1);
}
bool cmp(pair<int,int> p1,pair<int,int> p2)
{
    if(p1.first == p2.first) 
        return p1.second < p2.second;
    return p1.first>p2.first;
}
vector<int> Solution::solve(string A, vector<string> &B) {
    vector<int> ret;
    vector<pair<int,int>> v;
    node* head=nn();
    stringstream s(A);
    string token;
    while(getline(s,token,'_'))insert(head,token,0);
    for(int i=0;i<B.size();i++)
    {
        stringstream q(B[i]);
        int g=0;
        while(getline(q,token,'_'))
        {
           // cout<<token<<" "<<g<<endl;
            if(search(head,token,0))
            g++;
        }
        v.push_back(make_pair(g,i));
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++)
    ret.push_back(v[i].second);
    free(head);
    return ret;
}
