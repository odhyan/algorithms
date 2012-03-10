/* 	SUDOKU Solver
	Author: Saurabh Odhyan
	This program solves a SUDOKU puzzle.
	
	Input:
	First line contains an integer n, where n is the dimension of the puzzle.(nXn)
	Then give the  puzzle. Puzzle has n rows and n columns. Each number must 
	be an integer between 0-n. '0' represents empty position.
		
	Sample Input:
	9
	0 2 0 0 0 0 0 4 0
	0 0 3 9 2 8 6 0 0
	0 0 8 4 0 3 7 0 0
	3 0 0 7 8 2 0 0 9
	0 0 0 0 0 0 0 0 0
	5 0 0 6 9 1 0 0 7
	0 0 9 2 0 7 5 0 0
	0 0 7 8 6 9 2 0 0
	0 4 0 0 0 0 0 7 0	
	 
	Output:
	6 2 1 3 7 5 9 4 8 
	1 7 3 9 2 8 6 5 4 
	2 5 8 4 1 3 7 9 6 
	3 1 5 7 8 2 4 6 9 
	7 9 6 5 3 4 1 8 2 
	5 8 4 6 9 1 3 2 7 
	8 6 9 2 4 7 5 3 1 
	4 3 7 8 6 9 2 1 5 
	9 4 2 1 5 6 8 7 3 

*/

#include<iostream>
using namespace std;

int a[20][20],n;
int row_mask[20],col_mask[20];
bool done;

//Print the result
void print()
{
	cout<<endl<<"Solved Puzzle: "<<endl<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;	
	}
	cout<<endl;	
}

//This recursive function solves the puzzle
void solve(int r,int c)
{
	if(done) return; //puzzle already solved
	
	//We filled the matrix completely. The puzzle is solved :)
	if(r==n)
	{
		print();
		done=true;
		return;
	}	
	
	//Move to the next row
	if(c==n)
	{
		solve(r+1,0); 
	}
	
	if(a[r][c]==0) //Empty position
		for(int i=1;i<=n;i++)
		{
			if(row_mask[r]&(1<<i) || col_mask[c]&(1<<i)) continue; //We have already used this number in this row or column
			row_mask[r]|=(1<<i);
			col_mask[c]|=(1<<i);
			a[r][c]=i;
			solve(r,c+1);
			a[r][c]=0;
			row_mask[r]&=~(1<<i);
			col_mask[c]&=~(1<<i);
		}	
	else //Position already filled
		solve(r,c+1);
}

int main()
{
	done=false;
	memset(row_mask,0,sizeof(row_mask));
	memset(col_mask,0,sizeof(col_mask));
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]!=0)
			{
				row_mask[i]|=(1<<a[i][j]);
				col_mask[j]|=(1<<a[i][j]);
			}
		}	
	solve(0,0);
	if(!done) cout<<"No Solution"<<endl;
}