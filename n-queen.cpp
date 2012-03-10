/*	
Author: Saurabh Odhyan
N-Queen Problem	
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
int n,steps;
int mark[15][15];
bool can(int r,int c)
{
	for(int i=1;i<=n;i++)
	{
		if(mark[r][i]) return false;
		if(mark[i][c]) return false;
	}
	int x=r,y=c;
	while(x>0 && y>0)
		if(mark[x--][y--]) return false;
	x=r,y=c;
	while(x>0 && y<=n)
		if(mark[x--][y++]) return false;
	x=r,y=c;
	while(x<=n && y>0)
		if(mark[x++][y--]) return false;
	x=r,y=c;
	while(x<=n && y<=n)
		if(mark[x++][y++]) return false;
	return true;	
}
int solve(int r,int c)
{
	if(!can(r,c)) return 0;
	if(r==n) return 1;
	int res=0;
	mark[r][c]=1;
	for(int i=1;i<=n;i++)
	{
		res+=solve(r+1,i);
	}	
	mark[r][c]=0;	
	return res;	
}
int main()
{
	while(cin>>n)
	{
		memset(mark,0,sizeof(mark));
		int res=0;
		for(int i=1;i<=n;i++)
			res+=solve(1,i);
		cout<<res<<" solutions"<<endl;
	}
}