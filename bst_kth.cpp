/*
A Data Structure that supports the following operations:
1) insert(N) -: Insert element N into it in O(log n)
2) delete(N) -: delete element N from it in O(log n)
3) findKth()-: searches for Kth minimum element in O(log n)

This is a modified BST.
Every node keeps a count of number of nodes to its left subtree + number of nodes to its right subtree + 1(itself).

Author: Saurabh Odhyan
*/


struct BST{
	int v,c;
	BST* left;
	BST* right;
};

void insertNode(BST* &node,int& x){
	//cout<<node->v<<endl;
	if(node==NULL){
		node=new BST;
		node->v=x;
		node->c=1;
		node->left=NULL;
		node->right=NULL;
		return;
	}
	node->c++;
	if(x<node->v)
		insertNode(node->left,x);
	else	
		insertNode(node->right,x);
}

int findKth(BST* node,int k){
	if(node==NULL) return -1;
	//cout<<node->v<<" : "<<node->c<<" - "<<k<<endl;
	int t=0;
	if(node->right!=NULL) t=node->right->c;
	if(node->c-t==k) return node->v;
	if(node->left==NULL && node->right==NULL) return -1;
	if(node->left!=NULL && k<=node->left->c)
		return findKth(node->left,k);
	else{
		t=0;
		if(node->left!=NULL) t=node->left->c;
		return findKth(node->right,k-t-1);
	}	
}

BST* inorder_successor(BST* node){
	if(node->left==NULL) return node;
	return inorder_successor(node->left);
}
BST* inorder_predecessor(BST* node){
	if(node->right==NULL) return node;
	return inorder_predecessor(node->right);
}

void deleteNode(BST* &node,int x){
	//cout<<"Node "<<node->v<<endl;
	node->c--;
	if(node->v==x){
		if(node->left==NULL && node->right==NULL)
			node=NULL;
		else if(node->right==NULL){
			BST* node_delete=node;
			node=node->left;
			free(node_delete);
		}	
		else if(node->left==NULL){
			BST* node_delete=node;
			node=node->right;
			free(node_delete);
		}	
		else{
			if(node->left->c<node->right->c){
				BST* successor=inorder_successor(node->right);
				//cout<<"successor: "<<successor->v<<endl;
				node->v = successor->v;
				//node->c--;
				deleteNode(node->right, successor->v); 				
			}
			else{
				BST* predecessor=inorder_predecessor(node->left);
				//cout<<"predecessor: "<<predecessor->v<<endl;
				node->v = predecessor->v;
				//node->c--;
				deleteNode(node->left, predecessor->v); 				
			}         
		}
		return;
	}
	else if(x<node->v)
		deleteNode(node->left,x);
	else	
		deleteNode(node->right,x);
}

void traverse(BST* node,vi& a){
	if(node==NULL) return;
	//cout<<node->v<<" "<<node->c<<endl;
	a.PB(node->v);
	traverse(node->left,a);
	traverse(node->right,a);
}

int getHeight(BST* node){
	if(node==NULL) return 1;
	return 1+max(getHeight(node->left),getHeight(node->right));
}
void insert(BST* &root,int lo,int hi,vi& a){
	if(lo>hi) return;
	int mid=(lo+hi)/2;
	insertNode(root,a[mid]);
	insert(root,lo,mid-1,a);
	insert(root,mid+1,hi,a);
}
