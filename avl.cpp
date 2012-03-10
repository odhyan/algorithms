/**
* AVL Tree Implementation
* Author: Saurabh Odhyan
* Deletion not yet implemented
* Balance value at a node is Height(Right Subtree)-Height(Left Subtree)
*/

#include<iostream>

#define LEFT 1
#define RIGHT 2

using namespace std;

//Node structure
struct node{
	int data; //data
	int bal; //balance value
	node* left; //left child
	node* right; //right child
};

//Create a new node
node* make_node(int x)
{
	node* ret=(node*)malloc(sizeof(node));
	ret->data=x;
	ret->bal=0;
	ret->left=NULL;
	ret->right=NULL;
	return ret;
}

//Single right rotation
node* single_right_rotation(node* root)
{
	node* ret=root->left;
	node* tmp=ret->right;
	ret->right=root;
	root->left=tmp;
	return ret;
}

//Single left rotation
node* single_left_rotation(node* root)
{
	node* ret=root->right;
	node* tmp=ret->left;
	ret->left=root;
	root->right=tmp;
	return ret;
}

//Double left rotation
node* double_left_rotation(node* root)
{
	root->right=single_right_rotation(root->right);
	root=single_left_rotation(root);
	return root;
}

//Double right rotation
node* double_right_rotation(node* root)
{
	root->left=single_left_rotation(root->left);
	root=single_right_rotation(root);
	return root;
}

//Balance
void balance(node* &root,int dir)
{
	if(dir==LEFT){ 
		if(root->left->bal==-1){
			root->bal=root->left->bal=0;
			root=single_right_rotation(root);
		}
		else{
			if(root->left->right->bal==0){
				root->bal=root->left->bal=0;
			}
			else if(root->left->right->bal==1){
				root->bal=-1;
				root->left->bal=0;
			}
			else{
				root->bal=0;
				root->left->bal=1;
			}
			
			root=double_right_rotation(root);
		}
	}	
	else{
		if(root->right->bal==1){
			root->bal=root->right->bal=0;
			root=single_left_rotation(root);
		}
		else{
			if(root->right->left->bal==0){
				root->bal=root->right->bal=0;
			}
			else if(root->right->left->bal==-1){
				root->bal=1;
				root->right->bal=0;
			}
			else{
				root->bal=0;
				root->right->bal=-1;
			}
			
			root=double_left_rotation(root);
		}
	}	
	
}

//insertion
void insert(node* &root,int &x,bool &done)
{
	if(root==NULL){
		root=make_node(x);
		return;
	}
	if(x<root->data) //left subtree
	{
		insert(root->left,x,done);
		if(!done) //tree balances still need to be adjusted
		{
			root->bal--; //update balance
			
			if(root->bal==0)
				done=true;
			else if(abs(root->bal)>1)
			{
				balance(root,LEFT);
				done=true;
			}			
		}
	}
	else //right subtree
	{
		insert(root->right,x,done);
		if(!done) //tree balances still need to be adjusted
		{
			root->bal++; //update balance
			
			if(root->bal==0)
				done=true;
			else if(abs(root->bal)>1)
			{
				balance(root,RIGHT);
				done=true;
			}			
		}
	}
}

//get height of node x
int get_height(node* root,int x)
{
	if(root->data==x) //reached node x
		return 0;
	if(x<root->data)
		return 1+get_height(root->left,x);
	else
		return 1+get_height(root->right,x);
}

//inorder traversal
void inorder(node* root)
{
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

//find node x
bool find(node* root,int x)
{
	if(root==NULL) 
		return false; //node x not found
	if(root->data==x) 
		return true; //node x found
	if(x<root->data)
		return find(root->left,x);
	else
		return find(root->right,x);
}

//main
int main()
{
	node* root=(node*)malloc(sizeof(node));
	root=NULL;
	bool done;
	
	int n=13; //no of nodes
	int arr[]={1,4,3,7,9,8,2,5,6,12,40,33,15}; //input array
	for(int i=0;i<n;i++){
		done=false;
		insert(root,arr[i],done);
	}
	
	cout<<"Inorder traversal: "<<endl;
	inorder(root);	
	cout<<endl<<endl;
	
	sort(arr,arr+n);
	for(int i=0;i<n;i++)
		cout<<"Height of node "<<i<<" = "<<get_height(root,arr[i])<<endl;
}	
