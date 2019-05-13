/* 
Question:
Palindrome Integer
Asked in:  
HCL
Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.*/

int Solution::isPalindrome(int A) {
    if(A<0)
    return 0;
    int rev=0,temp=A;
    while(A>0)
    {
        int q=A%10;
        rev=rev*10+q;
        A=A/10;
    }
    return rev==temp;
}
