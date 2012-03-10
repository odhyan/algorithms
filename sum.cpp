/**
* Simulation of Binary Search Tree using the following problem:
* Given a bag with a maximum of 100 coins, determine the most fair division between two persons. 
* This means that the difference between the amount each person obtains should be minimized. 
* The value of a coin varies from 1 cent to 500 cents. It's not allowed to split a single coin.
*
* This is not the actual intended solution for this problem. 
* This solution just simulates the BST and is very inefficient. 
* The actual problem can be efficiently solved by Dynamic Programming.
*/

#include<iostream>
#include<vector>

using namespace std;

int sum=0,nodes=0;

struct Node
{
 int info,ps,ls;
 Node* left;
 Node* right;
}*root;
   

Node* newNode(int data,int presentsum,int leftsum)
{
 cout<<"Creating a new node . . .sum of weight: "<<presentsum<<endl;
 nodes++;
 Node* p=new Node;
 p->info=data;
 p->ps=presentsum;
 p->ls=leftsum;
 p->left=NULL;
 p->right=NULL;

 return(p);
}

Node* insert(Node* parent,Node* ptr, int data,int w,int ps,int val)
{
	
		
	if(ptr==NULL && ps<=sum/2)
	{
		if(parent!=NULL)
		{
			if(val==1)
				ps=parent->ps+w;
			else if(val==0)
				ps=parent->ps;
		}		
		return(newNode(data,ps,sum-ps));
	}	
	else
	{
		if(val==1)
			ps=ptr->ps+w;
		else if(val==0)
			ps=ptr->ps;
		
		if(ps<=sum/2)
		{
			ptr->left=insert(ptr,ptr->left,data,w,ps,1);
		    ptr->right=insert(ptr,ptr->right,data,w,ps,0);
		}	
    }
	return(ptr); 
}  
	
void inorder(Node* ptr)
{
   if(ptr!=NULL)
   {
      inorder(ptr->left);
      cout<<ptr->ps<<" ";
      inorder(ptr->right);
   }
}


int main()
{
	int n=5;
	int w[6]={5, 10, 12, 18, 25};
	int i,s=0;
	for(i=0;i<n;i++)
	{
		sum+=w[i];
	}	
	cout<<"Total sum of weight: "<<sum<<endl<<endl;
	root=newNode(0,0,sum);	
	
	for(i=0;i<n;i++)
		root=insert(NULL,root,i+1,w[i],0,1);
	cout<<"Total no. of nodes: "<<nodes<<endl;
	
	cout<<endl<<"Inorder:"<<endl;	
	inorder(root);	
	return 0;
}	
