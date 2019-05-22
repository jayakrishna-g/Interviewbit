/*Question:
 Stacks And Queues Min Stack
Min Stack
Asked in:  
Yahoo
Amazon
Adobe
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) – Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top element.
getMin() – Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.

Questions to ask the interviewer :

Q: What should getMin() do on empty stack? 
A: In this case, return -1.

Q: What should pop do on empty stack? 
A: In this case, nothing. 

Q: What should top() do on empty stack?
A: In this case, return -1
*/


int mini;
vector<int> v;
MinStack::MinStack() {
    mini=INT_MAX;
    v.clear();
}

void MinStack::push(int x) {
    v.push_back(x);
    mini=min(mini,x);
}

void MinStack::pop() {
    if(v.size()==0)
    return ;
    if(v.size()==1)
    mini=INT_MAX;
    else if(top()==mini)
    {
        mini=v[0];
        for(int i=0;i<v.size()-1;i++)
        mini=min(mini,v[i]);
    }
    v.pop_back();
}

int MinStack::top() {
    if(v.size()==0)
    return -1;
    return v[v.size()-1];
}

int MinStack::getMin() {
    if(v.size()==0)
    return -1;
   // cout<<mini;
    return mini;
}

