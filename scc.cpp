/**
* Find the strongly connected component in a graph
*/

#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<map>

using namespace std;

#define vi vector<int>
#define vvi vector< vector<int> >
#define pii pair<int,int>
#define MP make_pair
#define PB push_back
#define MAX 10000

vi G[MAX],GT[MAX],Gconn[MAX];
int comp[MAX],imp[MAX];
vector<pii> f;
bool vis[MAX];
vvi conn;
int tim;
void dfs(int pos)
{
	vis[pos]=1;
	tim++;
	for(int i=0;i<G[pos].size();i++)
		if(!vis[G[pos][i]])
			dfs(G[pos][i]);
	tim++;		
	f.PB(MP(tim,pos));		
}
void dfs2(int pos,vi& v)
{
	vis[pos]=1;
	v.PB(pos); 
	for(int i=0;i<GT[pos].size();i++)
		if(!vis[GT[pos][i]])
			dfs2(GT[pos][i],v);
}
void scc(int n,int m)
{		
		/*clear all global variables*/
		for(int i=0;i<=n;i++){
			G[i].clear();
			GT[i].clear();
			Gconn[i].clear();
		}	
		f.clear(); conn.clear();
		/***/
		
		/******Input******/
		int x,y;
		vector<pii> E(m);
		for(int i=0;i<m;i++)
		{
			cin>>x>>y;
			G[y].PB(x);
			GT[x].PB(y);
			E[i].first=y; E[i].second=x;
		}
		/*****************/
		
		memset(vis,0,sizeof(vis));
		tim=0;
		for(int i=1;i<=n;i++) 
			if(!vis[i]) dfs(i);
		sort(f.rbegin(),f.rend());	
		memset(vis,0,sizeof(vis));	
		for(int i=0;i<f.size();i++){
			vi v;
			if(!vis[f[i].second]){
				dfs2(f[i].second,v);
				conn.PB(v);	
			}	
		}
		for(int i=0;i<conn.size();i++)
			for(int j=0;j<conn[i].size();j++)
				comp[conn[i][j]]=i;
		
		/********Build the graph of SCC********/
		map<pii,bool> done;
		for(int i=0;i<m;i++){
			x=E[i].first; y=E[i].second;
			if(done.find(MP(comp[x],comp[y]))==done.end()){
				Gconn[comp[x]].PB(comp[y]);
				done[MP(comp[x],comp[y])]=1;
			}
		}
		/*************************************/
}		

int main() {
}
