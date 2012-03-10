/*
Author: Saurabh Odhyan
This program finds the distance between the closest pair of points in O(nlgn).
This program uses the Divide and Conquer Approach
*/

#include<iostream>
#include<vector>
#include<set>
#include<cmath>
#include<iomanip>
using namespace std;
#define PB push_back
#define pdd pair<double,double>
#define LL long long
#define vi vector<int>
const int INF=200000000;
vector<pdd>	P;
int n;

double dist(pdd A,pdd B)
{
	double dx=A.first-B.first;
	double dy=A.second-B.second;
	return sqrt(dx*dx+dy*dy);
}
double solve(int lo,int hi)
{
	if(hi-lo==1) return dist(P[lo],P[hi]);
	if(hi-lo==0) return INF;
	int mid=(lo+hi)/2;
	double res=min(solve(lo,mid),solve(mid,hi));
	vi left,right;
	for(int i=lo;i<mid;i++)
		if(abs(P[i].first-P[mid].first)<res+0.0005) left.PB(i);
	for(int i=mid;i<=hi;i++)
		if(abs(P[i].first-P[mid].first)<res+0.0005) right.PB(i);	
	for(int i=0;i<left.size();i++)
		for(int j=0;j<right.size();j++)
			res=min(res,dist(P[left[i]],P[right[j]]));
	return res;	
}
int main()
{
	double x,y;
	while(cin>>n && n)
	{	
		P.clear();
		for(int i=0;i<n;i++)
		{
			cin>>x>>y;
			P.PB(make_pair(x,y));
		}
		sort(P.begin(),P.end());
		double res=solve(0,n-1);
		cout<<res<<endl;		
	}	
}