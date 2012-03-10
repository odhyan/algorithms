/*
 * Kruskal Algorithm for Minimum Spanning Tree
 * Uses Disjoint Sets Data Structure
 * O(ElgV)
 * Author: Saurabh Odhyan
 */

#include<iostream>
#include<vector>

using namespace std;

#define MAX 1000
int p[MAX],rank[MAX];
void create_set(int x)
{
    p[x]=x;
    rank[x]=0;
}
int find_set(int x)
{
    if(p[x]!=x) p[x]=find_set(p[x]);
    return p[x];
}
void merge_set(int x,int y)
{
    int px=find_set(x);
    int py=find_set(y);
    if(rank[px]>rank[py])
        p[py]=px;
    else if(rank[px]<rank[py])
        p[px]=py;
    else if(px!=py)
    {
        p[py]=px;
        rank[px]++;
    }
}

struct Edge{
	int v1,
		v2,
		w;
	Edge(){}
	Edge(int _v1,int _v2,int _w){
		v1=_v1;
		v2=_v2;
		w=_w;
	}
	bool operator<(const Edge& E) const{ 
		return w<E.w;
	}
};
int main(){
	vector<Edge> E;

	int V, //no of vertices
		N; //no of edges
	cin>>V>>N;
	
	int x,y,w;
	for(int i=0;i<N;i++){
		cin>>x>>y>>w;
		E.push_back(Edge(x,y,w));
	}

	//Kruskal
	for(int i=0;i<V;i++)
		create_set(i);
	
	sort(E.begin(),E.end()); //sort edges according to edge weight
	int n=0, //no of vertices added to minimum spanning tree
		res=0; //weight of minimum spanning tree
	for(int i=0;i<N;i++){
		int x=E[i].v1;
		int y=E[i].v2;
		if(find_set(x)!=find_set(y)){
			merge_set(x,y);
			res+=E[i].w;
			cout<<x<<" - "<<y<<" : "<<E[i].w<<endl;
			n++;
		}
		if(n==V-1) break;
	}
	cout<<res<<endl;
}	
