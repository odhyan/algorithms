/*
Author: Saurabh Odhyan
EDIT DISTANCE for Approximate String Matching
Suppose we are given two strings a and b. This program finds the minimum number of operations needed to convert a into b.
The possible operations are:
1) Substitution
2) Insertion
3) Deletion
*/

#include<iostream>
using namespace std;
string a="abcdefghijkl",b="bcdeffghixkl";	
int dp[50][50];
const int INF=2000000;

int solve(int x,int y)
{
	if(x==a.size()) return b.size()-y;
	if(y==b.size()) return a.size()-x;
	int& res=dp[x][y];
	if(res!=-1) return res;
	res=INF;
	if(a[x]==b[y]) //match
		res=min(res,solve(x+1,y+1));
	else //no match
	{
		//delete
		res=min(res,1+solve(x+1,y));
		//insert
		res=min(res,1+solve(x,y+1));
		//substitute
		res=min(res,1+solve(x+1,y+1));
	}
	return res;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	cout<<solve(0,0)<<endl;
}