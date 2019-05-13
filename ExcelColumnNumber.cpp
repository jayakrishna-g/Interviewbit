/*Question:
Excel Column Number
Asked in:  
Amazon
Given a column title as appears in an Excel sheet, return its corresponding column number.*/
int Solution::titleToNumber(string A) {
    int sum=0;
    for(int i=0;i<A.size();i++)
    {
        sum+=((A[i]-'A'+1)*pow(26,(A.size()-i-1)));
    }
    return sum;
}
