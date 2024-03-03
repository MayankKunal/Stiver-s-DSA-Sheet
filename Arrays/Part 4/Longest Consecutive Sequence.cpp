#include<bits/stdc++.h>
using namespace std;
vector<int>ans;
int LongestConsecutiveSequence(vector<int>&arr)
{

	int n=arr.size();  //size of array

     
         if(n<2) return n; // return size of subarray is legth is less than 2
     priority_queue<int>pq;  // declare a priority queue which store element in
     // dreceasing oreder
     vector<int>temp; 
     
     for(int x:arr)
     {
     	pq.push(x); //push the element to queue
     }
     int prev=-1;  // intialise the prev variable to -1 at begining
     int count=1,maxCount=1; // count variables to count no of element;
     while(!pq.empty())
     {
            int curr=pq.top(); //take the top element of queue
            pq.pop();
            if(curr==prev-1)  
            {  // if current value is just less than previous one 
            	count++; //in crease count
            	temp.push_back(curr); 
            }
            else if(curr==prev)
            {
            	continue; //if the value of prev and curr is equal move to next element
            	
            }
            else
            { // if value do not match set the count to   1
            	temp.clear();  
            	temp.push_back(curr);
            	count=1;
            }
            prev=curr;  // set the previuos value to current at each iteration
            maxCount=max(count,maxCount); // take the maximum of count varibale
            if(ans.size()<temp.size()) ans=temp;
     }
     return maxCount;
}
int LongestConsecutiveSequence2(vector<int>&arr)
{
	unordered_set<int>st;  // declare a unordered set
	for(int x:arr)
	{
		st.insert(x);  // insert the arr element to set
	}  
	int count=1,maxCount=0;  // intialised the count and maxcount
    for(auto it:st)  //iterate throgh se element
    {
    	if(st.find(it-1)==st.end())  //get the first elemet
    		/*
               eg 101 100 99 104

               we will start our next/below traversal for either
               smalllest or largets elemt of subsequnce 
               in this we will proceed with smallest 
    		*/
    	{ //
  
    		int x=it;

    		count=1;
    	  while(st.find(x+1)!=st.end())  // iterate though set with just greater than curr
    	  {
    	  	count++;  // increase the count
    	  	x=x+1; // increse th element by 1
    	  }
    	  maxCount=max(count,maxCount);  // take maximun=m of count 
    	}
    	
    	
    }
    return maxCount;

}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
    	int x;
    	cin>>x;
    	arr.push_back(x);
    }

    cout<<LongestConsecutiveSequence(arr)<<" \n";
    cout<<LongestConsecutiveSequence2(arr)<<"\n";
// cout<<ans.size();
    sort(ans.begin(),ans.end());
    cout<<"Required SubSequence ->";
    for(int x:ans)
    {
    	cout<<x<<" ";
    }

}