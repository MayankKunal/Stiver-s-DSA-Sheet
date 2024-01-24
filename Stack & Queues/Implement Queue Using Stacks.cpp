#include<bits/stdc++.h>
using namespace std;
class MyQueue
{
  stack<int>st1,st2;
public:
  void Push(int x)
  {
       while(!st1.empty())
       {
       	st2.push(st1.top());
       	st1.pop();
       }
          st1.push(x);

        while(!st2.empty())
        {
        	st1.push(st2.top());
        	st2.pop();
        }
  }

  int Pop()
  {
  	if(!st1.empty())
  	{
  		int x=st1.top();
  		st1.pop();

  		return x;
  	}
  	else
  		return -1;

  }
  int Front()
  {
        if(!st1.empty())
  	{
  		int x=st1.top();

  		return x;
  	}
  	else
  		return -1;
  }

  bool isEmpty()
  {
           if(st1.size()) return false;
           else
           	 return true;
  }

};
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif

    MyQueue q;
  q.Push(3);
  q.Push(4);
  cout<<q.Front();
  q.Pop();
  cout<<q.Front();
  q.Pop();
  cout<<q.isEmpty();
  // cout << "The size of the queue is " << q.size() << endl;

}