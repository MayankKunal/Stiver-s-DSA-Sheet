#include<bits/stdc++.h>
using namespace std;
class MyStack {
public:
queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int n=q.size();
        while(n>1)
        {
            q.push(q.front());
            q.pop();
            n--;
        }
    }
    
    int pop() {
        if(q.size())
        {
        int x=q.front();
        q.pop();
        return x;
        }
        return -1;
    }
    
    int top() {
        if(q.size())
        return q.front();
        return -1;
        
    }
    
    bool isEmpty() {
        if(q.size())
        {
            return 0;
        }
        else
        return 1;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif


    MyStack st;

    st.push(1);
    st.push(2);
    st.push(3);

    cout<<st.top()<<"\n";
    cout<<st.pop()<<"\n";;
    cout<<st.top()<<"\n";;
    cout<<st.pop()<<"\n";;
    cout<<st.top()<<"\n";;
    cout<<st.pop()<<"\n";;
    cout<<st.top()<<"\n";

    cout<<st.isEmpty();


}