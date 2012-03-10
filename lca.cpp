/*
Find the LCA(Lowest Common Ancestor) of any 2 nodes in a tree
Time complexity: 
	Preprocess time: O(N)
	Query time: O(sqrt(N))
*/

#include<iostream>
using namespace std;
int P[1000]; //Ancestor of a node in previous section
int T[1000]; //Parent of a node
vi E[1000]; //Children of a node

//preprocess
void dfs(int node,int& nr)
{
	if(L[node]<nr){
		P[node]=1;
	}
	else{
		if(L[node]%nr==0)
			P[node]=T[node];
		else
			P[node]=P[T[node]];
	}
	for(int i=0;i<E[node].size();i++)
		dfs(E[node][i],nr);
}
//find LCA
int LCA(int x,int y)
{
	while(P[x]!=P[y])
		if(L[x]>L[y])
			x=P[x];
		else
			y=P[y];
	
	while(x!=y)
		if(L[x]>L[y])
			x=T[x];
		else
			y=T[y];
}
int main()
{
	
}