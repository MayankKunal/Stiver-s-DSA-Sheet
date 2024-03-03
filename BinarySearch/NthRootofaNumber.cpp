#include<bits/stdc++.h>
using namespace std;
int root(int n,int m,int mid)
{
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		ans*=mid;
		if(ans>m) return 2;
	}
	if(ans==m) return 1;
	else return 0;

}
int NthRoot(int n,int Number)
{
	int l=1,r=Number;

	while(l<=r)
	{
		int mid=(l+r)/2;
		int Root=root(n,Number,mid);
            if(Root==1)
            {
            	return mid;
            }
            else if(Root==0) l=mid+1;
            else r=mid-1;
	}
	return -1;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif
    int Number,Root;
    cin>>Number>>Root;
     
     cout<<NthRoot(Root,Number);


}