'''Power of 2
Asked in:  
Amazon
Find if Given number is power of 2 or not. 
More specifically, find if given number can be expressed as 2^k where k >= 1.'''

class Solution:
    # @param A : string
    # @return an integer
    def power(self, A):
        if A=="1":
            return 0
        else:
            k=int(A)
            if k&k-1==0:
                return 1
            else:
                return 0