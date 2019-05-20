/*Question
Minimum Characters required to make a String Palindromic
You are given a string. The only operation allowed is to insert characters in the beginning of the string. How many minimum characters are needed to be inserted to make the string a palindrome string

Example:
Input: ABC
Output: 2
Input: AACECAAAA
Output: 2*/

int Solution::solve(string A) {
    int count=0;
    int s=0;
    int e=A.size()-1;
    while(s<=e)
    {
        int i=s,j=e;
        while(i<=j)
        {
            if(A[i]!=A[j])
            break;
            i++;
            j--;
        }
        //cout<<i<<" "<<j<<" "<<A[i]<<" "<<A[j]<<endl;
        if(j<i)
        return A.size()-e-1;
        e--;
    }
}
