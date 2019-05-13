/*Question:
Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.
*/

vector<int> Solution::plusOne(vector<int> &A) {
    int i;
    for(i=A.size()-1;i>=0;i--)
    {
        if(A[i]!=9)
        {
            A[i]=A[i]+1;
            break;
        }
        else
        {
            A[i]=(A[i]+1)%10;
        }
    }
    if(i<0)
    {
        A.insert(A.begin(),1);
        return A;
    }
    int k=0;
    while(A[k]==0)
    k++;
    A.erase(A.begin(),A.begin()+k);
    return A;
}
