/*
Problem:
You are given an array containing n numbers. 
Out of these, two numbers repeat odd number 
of times and rest repeat even number of times.
Find the two numbers that repeat odd number of times.

Time complexity: O(n)
Space complexity: O(1) (Except the given array you cannot use additional space)
*/

#include<iostream>
using namespace std;
int n;
int a[1000];
void solve()
{
	int XOR=a[0];
	for(int i=1;i<n;i++)
		XOR^=a[i]; //XOR all elements. This will give A^B where A and B are required numbers
	int numA=-1,numB=-1; //set A and B to -1 initially	 
	for(int i=0;i<=31;i++) //find the first set bit. Infact we can use any set bit of the XOR.
	{
		if(!(XOR&(1<<i))) continue;
		//divide the number of the array into 2 groups based on which have set bit at i and which dont. Take their XOR.
		for(int j=0;j<n;j++)
			if(a[j]&(1<<i)){
				if(numA==-1)
					numA=a[j];
				else
					numA^=a[j];
			}
			else{
				if(numB==-1)
					numB=a[j];
				else
					numB^=a[j];
			}
		//cout<<numA<<" "<<numB<<endl;	
		break; //we got 1 set bit...now exit
	}
	cout<<numA<<" "<<numB<<endl;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	solve();	
}
