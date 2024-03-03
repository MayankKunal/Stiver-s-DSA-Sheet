#include<bits/stdc++.h>
using namespace std;
int help(vector<int>&Pages,int mid)
{
	int students=1,pages=0;
	for(int i=0;i<Pages.size();i++)
	{
		if(pages+Pages[i]<=mid)
		{
			pages+=Pages[i];
		}
		else
		{
			pages=Pages[i];
			students++;
		}
	}
	return students;

}
int AllocatePages(vector<int>&Pages,int student)
{
	int minAllocatedPages,maxAllocatedPages;
	for(int x:Pages)
	{
          minAllocatedPages=max(x,minAllocatedPages);
          maxAllocatedPages+=x;
	}
	while(minAllocatedPages<=maxAllocatedPages)
	{
		int allocatedPages=(minAllocatedPages+maxAllocatedPages)/2;
		int Students=help(Pages,allocatedPages);

		if(Students<=student) maxAllocatedPages=allocatedPages-1;
		else
		{
			minAllocatedPages=allocatedPages+1;
		}
	}
	return minAllocatedPages;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif
int n,student;
 cin>>n>>student;
 vector<int>Pages;
 for(int i=0;i<n;i++)
 {
 	int x;
 	cin>>x;
Pages.push_back(x);
 }

 cout<<AllocatePages(Pages,student);
}