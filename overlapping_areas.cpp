/*
Author: Saurabh Odhyan
Program to find the total Area of the union of N overlapping rectangles using Line Sweep Algorithm.
Time Complexity: O(N^2)

*/

#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<queue>
#include<ctime>

using namespace std;
#define LL long long
#define PB push_back
#define vi vector<int>

#define LEFT 1
#define RIGHT 2
#define TOP 3
#define BOTTOM 4


//Point Class
class Point{
public:
	int x,y;
	Point(){}
	Point(int a,int b) { x=a; y=b; }
	bool operator<(const Point& p) const
	{
		if(x!=p.x) return x<p.x;
		return y<p.y;
	}	
};

//Class for Horizontal Edge
class HEdge{
public:
	int rectID;
	Point A,B; //end points joining the edge
	int type; //top,bottom
	HEdge(){}
	HEdge(int id,Point a,Point b,int t) { rectID=id; A=a; B=b; type=t; }
	bool operator<(const HEdge& he) const
	{
		return A.y<he.A.y;
	}
};

//Class for Vetical Edge
class VEdge{
public:
	int rectID;
	Point A,B; //end points joining the edge
	int type; //left,right
	VEdge(){}
	VEdge(int id,Point a,Point b,int t) { rectID=id; A=a; B=b; type=t; }
	bool operator<(const VEdge& ve) const
	{
		return A.x<ve.A.x;
	}
};

//Rectangle Class
class Rect{
public:
	Point TL,BR; //top-left, bottom-right
	Rect(){}
	Rect(Point a,Point b) { TL=a; BR=b; }
};

//This array marks all active rectangles at any moment
bool Active[105];

//Main
int main()
{
	vector<Rect> Input; //store input rectangles
	vector<HEdge> HE; //store horizontal edges of rectangles
	vector<VEdge> VE; //store vertical edges of rectangles
	
	int n; //no of rectangles
	cin>>n;
	for(int i=0;i<n;i++)
	{
		Point tl,br;
		cin>>tl.x>>tl.y>>br.x>>br.y;
		Rect r(tl,br);
		Input.PB(r);
		Point tr(br.x,tl.y),bl(tl.x,br.y);
		HEdge he1(i,tl,tr,TOP),he2(i,bl,br,BOTTOM);
		VEdge ve1(i,tl,bl,LEFT),ve2(i,tr,br,RIGHT);
		HE.PB(he1); HE.PB(he2);
		VE.PB(ve1); VE.PB(ve2);
	}
	
	sort(HE.begin(),HE.end());
	sort(VE.begin(),VE.end());
	
	memset(Active,0,sizeof(Active)); //Initially all rectangles are inactive
	
	int AREA=0; //start with 0 area
	
	//outer loop for vertical sweep line
	for(int i=0;i<VE.size();i++)
	{
		VEdge ve=VE[i];
		if(ve.type==LEFT) //if left edge of rectangle
			Active[ve.rectID]=1; //make it active
		else //if right edge of rect
			Active[ve.rectID]=0; //make it inactive
		if(i+1<VE.size() && VE[i+1].A.x==VE[i].A.x) continue;
		
		int actv=0,lastY=0;
		int area=0; //counts the points on vertical sweep line that are on active rectangles
				
		//inner loop for horizontal sweep line
		for(int j=0;j<HE.size();j++)
		{
			HEdge he=HE[j];
			if(!Active[he.rectID]) continue;
			if(he.type==BOTTOM) //if bottom edge of rectangle
			{ 
				actv++; //one more active rectangle on the current vertical and horizontal sweep lines
				if(actv==1) lastY=he.A.y;
			}	
			else //if top edge of rectangle
			{
				actv--; //remove from list of active rectangle on the current vertical and horizontal sweep lines
				if(actv==0) area+=he.A.y-lastY; //no more active rectangles so add the area
			}	
		}
		if(i+1<VE.size()) area*=VE[i+1].A.x-VE[i].A.x; //multiply the no of points on the vertical sweep line with the width upto next vertical sweep line
		AREA+=area; 
	}
	cout<<AREA<<endl; //final area
}