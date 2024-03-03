#include<bits/stdc++.h>
using namespace std;
/* 
 finding x^n;
*/
double Power(double x,int n)
{
	double ans=1.0;  //declare a ans variable to store the result
     long p=abs(n); //take a dummy variable p to store the +ve value of n 
     while(p)
     {
     	if(p%2)  //if value of p is odd multiply the x value to ans
     	{
     		ans*=x;
     		p--;  // decrease value of p
     	}
     	else
     	{
     		x*=x;
     		p/=2;

       // if p is even mutilpy x with itself 
     		/*
             eg let x=2 n=10;
               2^10;

               2^10=2*2*2*2*2*2*2*2*2*2;
               => 2^2*2^2*2^2*2^2 => (2^2)^5
                 4^5
                //ly 4*4^4=> 4*(4*4*4*4)=>
                    4*(4^2)^2;
                    4*256=1024

     		 */
     		
     	}
     }
     if(n>0) return ans;
     return double(1/ans);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif
double x;
int n;
cin>>x>>n;
cout<<Power(x,n);
}