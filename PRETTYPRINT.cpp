/*Question:
Print concentric rectangular pattern in a 2d matrix. 
Let us show you some examples to clarify what we mean.

Example 1:

Input: A = 4.
Output:

4 4 4 4 4 4 4 
4 3 3 3 3 3 4 
4 3 2 2 2 3 4 
4 3 2 1 2 3 4 
4 3 2 2 2 3 4 
4 3 3 3 3 3 4 
4 4 4 4 4 4 4 */

vector<vector<int> > Solution::prettyPrint(int A) {
    vector<vector<int>> ret;
    int count=A;
    int lim=2*A-1;
    int i;
    for(i=0;i<=lim/2;i++)
    {
        vector<int> row;
        count=A;
        for(int j=0;j<i;j++)
        {
            row.push_back(count--);
        }
        for(int j=0;j<lim-2*i;j++)
        {
            row.push_back(count);
        }
        for(int j=0;j<i;j++)
        {
            row.push_back(++count);
        }
        ret.push_back(row);
    }
    int j=i;
    int g=2;
    for(;i<lim;i++,g++)
    {
        ret.push_back(ret[j-g]);
    }
    return ret;
}
