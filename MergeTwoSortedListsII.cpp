/*
Question:
Merge Two Sorted Lists Ii
Merge Two Sorted Lists II
Asked in:  
Adobe
Expedia
Microsoft
Given two sorted integer arrays A and B, merge B into A as one sorted array.

 Note: You have to modify the array A to contain the merge of A and B. Do not output anything in your code.
TIP: C users, please malloc the result into a new array and return the result. 
If the number of elements initialized in A and B are m and n respectively, 
the resulting size of array A after your code is executed should be m + n*/

void Solution::merge(vector<int> &A, vector<int> &B) {

    /*for(int i=0;i<B.size();i++)
    A.push_back(B[i]);
    sort(A.begin(),A.end());*/
    vector<int> C=A;
    A.clear();
    int i=0;
    int j=0;
    //cout<<i<<" "<<B.size()<<" "<<j<<" "<<C.size()<<endl;
    while(i<B.size()&&j<C.size())
    {
        if(B[i]<=C[j]){
        A.push_back(B[i]);
        i++;
        }
        else{
        A.push_back(C[j]);
        j++;
        }
    }
    //cout<<i<<" "<<B.size()<<" "<<j<<" "<<C.size()<<endl;
    while(i<B.size()){
    A.push_back(B[i]);
    i++;
    }
    while(j<C.size()){
    A.push_back(C[j]);
    j++;
    }
}
