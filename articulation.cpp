/*
Finding articulation points using DFS
Complexity: O(E+V)
*/

const int MAX=50000; //no of edges + no of vertices
vi A[MAX]; //Adj list
bool vis[MAX]; //visited nodes
int tim=0; //time counter
int d[MAX]; //discovery time of vertex from root
int low[MAX]; //discovery time of the vertex closest to the root and reachable from v by following zero or more edges downward, and then at most one back edge.
vector<int> art; //articulation point is stored here whenever found

void dfs(int v)
{
	vis[v]=1;
	tim++;
	low[v]=d[v]=tim;
	for(int i=0;i<A[v].size();i++){ //for each vertex connected to v
		int w=A[v][i];
		if(!vis[w]){ //if i is not visited yet
			dfs(w);
			low[v]=min(low[v],low[w]);
			if(low[w]>=d[v]) //no back edge from i to ancestor of v					
				art.PB(v);								
		}
		else
			low[v]=min(low[v],d[w]);		
	}
}	
