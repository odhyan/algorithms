/*
 * 0-1 Knapsack problem
 * Author: Saurabh Odhyan
 */

#include<iostream>
#include<vector>
using namespace std;

#define INF 99999999

int N,
	W[100],
	V[100],
	maxW,
	dp[100][1000];

/* Recursive */
int knapsack(int pos,int w){
	if(w > maxW) return -INF;
	if(pos == N) return 0;
	int& res = dp[pos][w];
	if(res!=-1) return res;
	res = max(V[pos]+knapsack(pos+1,w+W[pos]),knapsack(pos+1,w));
	return res;
}

/* Iterative */
int knapsack() {
   int n = N;
   int k = maxW;
   int c;

   int matrix[100][1000];	
   for(int i=0; i<n; i++) 
     for (int j=0;j<=k;j++) 
       matrix[i][j] = 0;
   for(int i=W[0]; i<=k; i++)
     matrix[0][i] = V[0];
  
   for(int i=1;i<n;i++)
     for(int j=0;j<=k;j++) {
       if(j-W[i] >= 0) 
	      c = matrix[i-1][j-W[i]]+V[i];
       else	
	      c = 0;
       if(c < matrix[i-1][j]) 
	      c = matrix[i-1][j];
        matrix[i][j] = c;
     }
   return matrix[n-1][k];		
}

int main(){
	cin>>maxW;
	N = 0;
	while(cin>>W[N]){
		cin>>V[N];
		N++;
	}
	memset(dp,-1,sizeof(dp));
	int res = knapsack(0,0);
	if(res == INF) res = 0;
	cout<<res<<endl;
	cout<<knapsack()<<endl;
}
	
