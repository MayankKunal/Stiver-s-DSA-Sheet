#include<bits/stdc++.h>
using namespace std;
 vector<vector<int>> mergeIntervals(vector<vector<int>>& arr) {
     int n=arr.size();  // get the size of interval

	sort(arr.begin(),arr.end()); //sort arr in ascending order

	vector<int>temp;  //declare a temp vector to store the interval at each step
	vector<vector<int>>ans;  // declare a ans vector of vector to stroe results

	for(int i=0;i<n;i++)  //traverse through the matrix row wise
	{
		if(temp.size()>1 && temp.back()>=arr[i][0])  // temp vector
			//contains more than 2 value means start and end
		{
			int t=temp.back(); //get end value of an inerval
                t=max(t,arr[i][1]); //compare with start of next interval to
                 // get bigger end value of an interval
             temp.pop_back();  //pop the end of interval
             temp.push_back(t); // insert new back value interval
		}
		else  
		{  // if start of next interval is > than
				// end of current interval means no overlapping 
				// OR if it just start
			if(temp.size())    //temp has values 
				ans.push_back(temp);// push it to ans for store
			temp.clear(); // clear temp for new interval
			temp.push_back(arr[i][0]);  // push interval start to temp
			temp.push_back(arr[i][1]);  // push interval end to temp
		}
	}
	if(temp.size()) ans.push_back(temp);  // important what if last interval overlaps
	// with previous one push the interval in end;
	return ans;
    }
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif
    int n,m;
     cin>>n>>m;
     vector<vector<int>>arr;
     vector<vector<int>>ans;

     for(int i=0;i<n;i++)
     {
     	vector<int>temp;
     	for(int j=0;j<m;j++)
     	{
     		int p;
     		cin>>p;
        temp.push_back(p);

     	}
     	arr.push_back(temp);
     }
     cout<<n<<" "<<m<<endl;
   ans=mergeIntervals(arr);
     for(int i=0;i<ans.size();i++)
     {
     	cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
     }
// cout<<n<<" "<<m<<endl;
}