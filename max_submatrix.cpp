/**
 * Find the submatrix with maximum sum
 * O(N^4);
 * Author: Saurabh Odhyan
 */
#include<iostream>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	int a[n][m],sum[n][m];
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>a[i][j];
		}
	}
	//preprocess - take all sums from 0,0 - i,j
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			sum[i][j] = 0;		
			for(int x=0;x<=i;x++) {
				for(int y=0;y<=j;y++) {
					sum[i][j] += a[x][y];
				}
			}
			cout<<i<<","<<j<<" = "<<sum[i][j]<<endl;
		}
	}

	int max_sum = 0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			for(int x=i;x<n;x++) {
				for(int y=j;y<m;y++) {
					int s = sum[x][y];
					if(j >= 1) {
						s -= sum[x][j-1];
					}
					if(i >= 1) {
						s -= sum[i-1][y];
					}
					if(i >= 1 && j >= 1) {
						s += sum[i-1][j-1];
					}
					cout<<i<<","<<j<<" - "<<x<<","<<y<<" = "<<s<<endl;
					max_sum = max(max_sum,s);
				}
			}
		}
	}

	cout<<max_sum<<endl;
}



