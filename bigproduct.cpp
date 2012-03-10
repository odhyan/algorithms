/*
Author: Saurabh Odhyan
Program to compute product of very big integers
*/

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

class BIG_PRODUCT {
	private:
		string a,b;
	public:
		vector<int> str_intvec(string s)
		{
			vector<int> a;
			for(int i=0;i<s.length();i++)
				a.push_back((int)(s[i]-'0'));
			return a;
		}	

		vector<int> add(vector<int> x1,vector<int> x2)
		{
			int s=0,c=0;
			for(int k=x2.size();k<x1.size();k++)
				x2.push_back(0);	
			for(int i=0;i<x1.size();i++)
			{
				s=x1[i]+x2[i]+c;
				x2[i]=s%10;
				c=s/10;
			}	
			if(s>0)
			{
				while(c>0)
				{
					int a=c%10;
					x2.push_back(a);
					c=c/10;
				}
			}	
			return x2;
		}	

		vector<int> multiply(vector<int> a,vector<int> b)
		{
			vector<int> p,s(max(a.size(),b.size()),0);
			for(int i=a.size()-1;i>=0;i--)
			{
				int c=0;
				int y=a.size()-1;
				p.clear();
				while(y>i)
				{
					p.push_back(0);
					y--;
				}	
				for(int j=b.size()-1;j>=0;j--)
				{
					int x=a[i]*b[j]+c;
					p.push_back(x%10);
					c=x/10;
				}
				if(c!=0)
					p.push_back(c);
				s=add(p,s);
			}
			return s;
		}	

		vector<int> format(vector<int> f)
		{
			vector<int> s;
			int x=1,l=0,k=0;
			for(int i=f.size()-1;i>=0;i--)
			{
				if(!(x==1 && f[i]==0))
				{
					s.push_back(f[i]);
					l++;
					x=0;
				}		
			}
			if(x)	
				s.push_back(0);	
			return s;	
		}
		vector<int> getproduct(string s1,string s2)	
		{
			vector<int> a,b,c;
			a=str_intvec(s1);
			b=str_intvec(s2);
			c=multiply(a,b);
			return format(c);
		}	
};		
		
int main()
{
	string s1,s2;
	BIG_PRODUCT bp;
	while(cin>>s1>>s2)
	{
		vector<int> res=bp.getproduct(s1,s2);
	}
	return 0;
}	