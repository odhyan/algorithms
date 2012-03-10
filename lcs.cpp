/**
* Solution to longest common subsequence problem using memoization
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int memo[100][100];
string A,B,C;

int LCS(int a,int b)
{
	if(a==A.size() || b==B.size()) return 0;
	int& res=memo[a][b];
	if(res!=-1) return res;
	res=0;
	if(A[a]==B[b])
		res=max(res,1+LCS(a+1,b+1));
	else	
		res=max(LCS(a+1,b),LCS(a,b+1));
	return res;	
}

void construct(int a,int b)
{
	if(a==A.size() || b==B.size()) return;
	if(A[a]==B[b]){
		C+=A[a];
		construct(a+1,b+1);
		return;
	}
	if(LCS(a,b+1)>LCS(a+1,b))
		construct(a,b+1);
	else
		construct(a+1,b);		
}

int main()
{
	while(cin>>A>>B)
	{
		C.clear();
		memset(memo,-1,sizeof(memo));
		int LEN=LCS(0,0);
		cout<<"Length: "<<LEN<<endl;
		if(LEN>0){
			cout<<"LCS Length: "<<LEN<<endl;
			construct(0,0);
			cout<<C<<endl;
		}	
	}	
	return 0;
}
