/*
Author: Saurabh Odhyan
This program finds the distance between the closest pair of points in O(nlgn).
This program uses the Line Sweep Algorithm

Incorrect
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
double solve()
{
	set<pdd> D; //set that stores closest elements from left of p
	for(int i=0;i<n;i++)
		D.insert(P[i]);
	if(D.size()<n) return 0;	
	double res=INF; //inital closest distance
	for(int p=0;p<n;p++) //for each point p
	{
		double x=P[p].first,y=P[p].second;
		for(set<pdd>::iterator itr=D.begin();itr!=D.end();itr++)
		{
			pdd left=*itr;
			if(left.first>x) continue; //no action if point is on right of p
			if(left.first-x>res || abs(left.second-y)>res)
			{
				D.erase(*itr);
				itr--;
			}
			else	
			{
				double d=dist(P[p],left);
				if(d==0) continue;
				res=min(res,d);	
			}	
		}
	}
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
		double res=solve();
		cout<<res<<endl;		
	}	
}